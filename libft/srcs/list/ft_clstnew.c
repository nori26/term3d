#include "ft_list.h"
#include "ft_utils.h"
#include <stdlib.h>

t_clist	*ft_clstnew(void *data)
{
	t_clist	*new;

	if (!ft_setptr(&new, malloc(sizeof(t_clist))))
		return (NULL);
	new->data = data;
	new->next = new;
	new->prev = new;
	return (new);
}
