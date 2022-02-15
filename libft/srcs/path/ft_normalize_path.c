#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"
#include "ft_path.h"
#include "ft_string.h"

static t_clist	*split_path_to_token(char *rootpath)
{
	t_clist	*tokens;
	char	*remained;
	char	*path;

	tokens = ft_clstnew(NULL);
	if (!tokens)
		return (NULL);
	remained = rootpath;
	while (get_next_token(&remained, "/", &path))
	{
		if (!*path)
			continue ;
		if (!ft_clstnew_add_back(tokens, path))
		{
			ft_clst_clear(&tokens, NULL);
			return (NULL);
		}
	}
	return (tokens);
}

size_t	get_pathlen(t_clist *tokens)
{
	char			*path;
	size_t			len;
	const size_t	num_of_slash = ft_clst_size(tokens);

	len = 0;
	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		path = tokens->data;
		len += ft_strlen(path);
		tokens = tokens->next;
	}
	return (len + num_of_slash);
}

void	join_tokens(t_clist *tokens, char *buf, size_t len)
{
	size_t	i;
	char	*path;

	i = 0;
	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		path = tokens->data;
		buf[i++] = '/';
		i += ft_strlcpy(buf + i, path, len + 1);
		tokens = tokens->next;
	}
}

char	*create_normalized(t_clist *tokens)
{
	size_t	len;
	char	*normalized;

	if (!ft_clst_size(tokens))
		return (ft_strdup("/"));
	len = get_pathlen(tokens);
	normalized = malloc(len + 1);
	if (!normalized)
		return (NULL);
	join_tokens(tokens, normalized, len);
	return (normalized);
}

void	resolve_relative_current(t_clist *tokens)
{
	char	*path;
	t_clist	*next;

	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		next = tokens->next;
		path = tokens->data;
		if (ft_streq(path, "."))
			ft_clst_popdel(tokens, NULL);
		tokens = next;
	}
}

void	resolve_relative_parent(t_clist *tokens)
{
	char	*path;
	t_clist	*next;

	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		next = tokens->next;
		path = tokens->data;
		if (ft_streq(path, ".."))
		{
			if (!ft_clst_isend(tokens->prev))
				ft_clst_popdel(tokens->prev, NULL);
			ft_clst_popdel(tokens, NULL);
		}
		tokens = next;
	}
}

void	resolve_relative_path(t_clist *tokens, bool is_relative)
{
	resolve_relative_current(tokens);
	if (is_relative)
		return ;
	resolve_relative_parent(tokens);
}

char	*ft_normalize_path(char *path)
{
	char	*normalized;
	char	*path_cpy;
	t_clist	*tokens;

	path_cpy = ft_strdup(path);
	if (!path_cpy)
		return (NULL);
	tokens = split_path_to_token(path_cpy);
	if (!tokens)
	{
		free(path_cpy);
		return (NULL);
	}
	resolve_relative_path(tokens, ft_is_relative_path(path));
	normalized = create_normalized(tokens);
	ft_clst_clear(&tokens, NULL);
	free(path_cpy);
	return (normalized);
}

// #include <stdio.h>

// #define TEST(a, b) test(a, b,  __LINE__)
// bool	okok = true;

// __attribute__((destructor))
// static void destructor()
// {
// 	if (okok)
// 	    puts("OK");
// }

// void	test(char *path, char *expect, int line)
// {
// 	char *res;

// 	(void)expect;
// 	res = normalize_path(path);
// 	printf("%s\n", path);
// 	free(res);
// }
// //ft_join_path 修正
// int main()
// {
// 	// TEST("", "", NULL);
// 	// TEST("", "/", "/");
// 	// TEST("", "//", "//");
// 	// TEST("/", "", NULL);
// 	// TEST("/", "/", "/");
// 	// TEST("/", "//", "//");
// 	// TEST("//", "", NULL);
// 	// TEST("//", "/", "/");
// 	// TEST("//", "//", "//");

// 	// TEST("", "./", NULL);
// 	// TEST("", "./", NULL);
// 	// TEST("", ".//", NULL);
// 	// TEST("/", "./", "/");
// 	// TEST("/", ".//", "/");
// 	// TEST("//", "./", "//");
// 	// TEST("//", ".//", "//");

// 	// TEST("1", "a", NULL);
// 	// TEST("1", "/a", "/a");
// 	// TEST("1", "a/", NULL);
// 	// TEST("/1", "a", "/1/a");
// 	// TEST("/1", "/a", "/a");
// 	// TEST("/1", "a/", "/1/a");
// 	// TEST("1/", "a", NULL);
// 	// TEST("1/", "/a", "/a");
// 	// TEST("1/", "a/", NULL);

// 	// TEST("1", "//a", "//a");
// 	// TEST("1", "a//", NULL);
// 	// TEST("/1", "//a", "//a");
// 	// TEST("/1", "a//", "/1/a");
// 	// TEST("1/", "//a", "//a");
// 	// TEST("1/", "a//", NULL);

// 	// TEST("//1", "a", "//1/a");
// 	// TEST("//1", "/a", "/a");
// 	// TEST("//1", "a/", "//1/a");
// 	// TEST("//1", "a", "//1/a");
// 	// TEST("//1", "/a", "/a");
// 	// TEST("//1", "a/", "//1/a");
// 	// TEST("//1/", "a", "//1/a");
// 	// TEST("//1/", "/a", "/a");
// 	// TEST("//1/", "a/", "//1/a");

// 	// TEST("1", "./a", NULL);
// 	// TEST("1", ".//a", NULL);
// 	// TEST("1", "./a/", NULL);
// 	// TEST("/1", "./a", "/1/a");
// 	// TEST("/1", ".//a", "/1/a");
// 	// TEST("/1", "./a/", "/1/a");
// 	// TEST("1/", "./a", NULL);
// 	// TEST("1/", ".//a", NULL);
// 	// TEST("1/", "./a/", NULL);

// 	// TEST("//1", "./a", "//1/a");
// 	// TEST("//1", ".//a", "//1/a");
// 	// TEST("//1", "./a/", "//1/a");
// 	// TEST("//1", "./a", "//1/a");
// 	// TEST("//1", ".//a", "//1/a");
// 	// TEST("//1", "./a/", "//1/a");
// 	// TEST("//1/", "./a", "//1/a");
// 	// TEST("//1/", ".//a", "//1/a");
// 	// TEST("//1/", "./a/", "//1/a");
// }
