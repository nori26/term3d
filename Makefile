NAME		:= term3d
SHELL		:= /bin/bash

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -MMD -MP
IOPTIONS	= $(addprefix -I , $(INCLUDES))
LOPTIONS	= -L$(LIBFTDIR)
LIBS		:= -lm -lft

SRCDIR		:= srcs
OBJDIR		:= ./obj
LIBFTDIR	:= ./libft
LIBFT		:= $(LIBFTDIR)/libft.a

INCLUDE		:= ./includes
LIBINCLUDE	:= $(LIBFTDIR)/includes
INCLUDES	:= $(INCLUDE) $(LIBINCLUDE)

DIR1		:= $(SRCDIR)/vector
DIR2		:= $(SRCDIR)/input
DIR3		:= $(SRCDIR)/wrapper
DIR4		:= $(SRCDIR)/adjust
DIR5		:= $(SRCDIR)/utils
DIR6		:= $(SRCDIR)/draw

MAIN		:= srcs/main.c\

SRC1	=\
	srcs/vector/vect_print.c\
	srcs/vector/vector_utils.c\
	srcs/vector/vector_utils2.c\

SRC2	=\
	srcs/input/file_to_list.c\
	srcs/input/input.c\
	srcs/input/parse.c\
	srcs/input/validate_filename.c\
	srcs/input/validate_lines.c\

SRC3	=\
	srcs/wrapper/ft_fopen.c\
	srcs/wrapper/ft_getline.c\
	srcs/wrapper/ft_strtod.c\

SRC4	=\
	srcs/adjust/adjust.c\
	srcs/adjust/centering.c\
	srcs/adjust/scaling.c\
	srcs/adjust/scaling2.c\

SRC5	=\
	srcs/utils/utils.c\

SRC6	=\
	srcs/draw/draw.c\
	srcs/draw/fill_screen.c\

SRCS		:= $(MAIN)$(SRC1)$(SRC2)$(SRC3)$(SRC4)$(SRC5)$(SRC6)
OBJS		:= $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCS:.c=.o))
DEPENDS		:= $(OBJS:.o=.d)

PURPLE		:= \033[1;35m
GREEN		:= \033[1;32m
RESET		:= \033[0;39m

# ifdef WITH_BONUS
# NAME	= philo_bonus
# OBJS	= $(shell basename -a $(B_SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# DEPENDS	= $(shell basename -a $(B_SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# endif

all		: _libft $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CC) $(CFLAGS) $(IOPTIONS) -c $< -o $@
	@echo -e "	""$(GREEN)$@$(RESET)"

t	: $(OBJS) $(LIBFT)
	ar -rcs test.a $(OBJS)
	gcc -g -fsanitize=address $(IOPTIONS) input_test.c test.a $(LIBFT) -o test

$(NAME)	: $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(IOPTIONS) $(LOPTIONS) $(OBJS) $(LIBS) -o $@
	@echo -e "\n$(PURPLE) build	$(GREEN)$@$(RESET)"

_libft:
	@$(MAKE) -C $(LIBFTDIR)

$(LIBFT): _libft

clean	: rm_reloc
#	# @make b_clean WITH_BONUS=1

fclean	: clean rm_exec
#	@make b_fclean WITH_BONUS=1

# bonus	:
# 	@make WITH_BONUS=1

b_clean	: rm_reloc

b_fclean: rm_exec

rm_reloc:
	$(RM) -r $(OBJDIR) $(LIBFTDIR)/$(OBJDIR)

rm_exec	:
	$(RM) $(NAME) $(LIBFTDIR)/libft.a

add		:
	bash header.sh "$(DIR1)" $(INCLUDE)/vector.h
	bash header.sh "$(DIR2)" $(INCLUDE)/input.h
	bash header.sh "$(DIR3)" $(INCLUDE)/wrapper.h
	bash header.sh "$(DIR4)" $(INCLUDE)/adjust.h
	bash header.sh "$(DIR5)" $(INCLUDE)/utils.h
	bash header.sh "$(DIR6)" $(INCLUDE)/draw.h
	bash make.sh $(DIR1) SRC1
	bash make.sh $(DIR2) SRC2
	bash make.sh $(DIR3) SRC3
	bash make.sh $(DIR4) SRC4
	bash make.sh $(DIR5) SRC5
	bash make.sh $(DIR6) SRC6

re		: fclean all

debug	: CFLAGS += -g -fsanitize=address
debug	: re

TESTDIR		= tests
GTESTDIR	= $(TESTDIR)/googletest
GTESTLIB	= $(GTESTDIR)/gtest.a
TESTCASES	= $(wildcard $(TESTDIR)/$(F)*test.cpp) $(TESTDIR)/test_util.cpp
TESTOBJS	= $(filter-out %main.o, $(OBJS))
TESTLIBS	= -lpthread -L$(LIBFTDIR) $(LIBS)
TESTER		= tester

$(GTESTLIB):
	$(MAKE) -C $(TESTDIR)

$(TESTER)	: $(NAME) $(GTESTLIB) $(TESTCASES)
	clang++ -I$(GTESTDIR) $(IOPTIONS) $(GTESTLIB) $(TESTCASES) $(TESTOBJS) $(TESTLIBS) -o $@

gen		:
	python3 $(TESTDIR)/casemaker.py

test	: $(TESTER)
	./$<

leak	: $(TESTER)
	valgrind --leak-check=full ./$<

cinorm	:
	@norminette includes libft $(shell find srcs -mindepth 1 -type d -not -name debug) \
		| grep -v 'Missing' \
		| grep -v 'WRONG_SCOPE_COMMENT' \
		| grep -v 'TOO_MANY_FUNCS' \
		| grep -v ': OK!' \
		| tee /dev/stderr \
		| grep 'Error: ' > /dev/null; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

norm	:
	@norminette includes libft srcs \
		| grep -v ': OK!'; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

.PHONY	: all clean fclean re bonus add norm rm_exec rm_reloc b_clean b_fclean head _libft test