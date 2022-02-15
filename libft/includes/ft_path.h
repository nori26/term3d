#ifndef FT_PATH_H
# define FT_PATH_H
# include <stdbool.h>
typedef struct s_clist t_clist;

bool	ft_is_relative_path(const char *path);
char	*create_normalized(t_clist *tokens);
char	*ft_join_path(char *parent, char *child);
char	*ft_normalize_path(char *path);
size_t	get_pathlen(t_clist *tokens);
void	join_tokens(t_clist *tokens, char *buf, size_t len);
void	resolve_relative_current(t_clist *tokens);
void	resolve_relative_parent(t_clist *tokens);
void	resolve_relative_path(t_clist *tokens, bool is_relative);

#endif
