extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "check.hpp"
#include "leaks.hpp"
#include "sigsegv.hpp"
#include <string.h>

void	freeList(t_list *head)
{
	if (head)
		freeList((t_list *)head->next);
	free(head);
}
void	*addOne(void *p)
{
	void	*r;

	r = malloc(sizeof(int));
	*(int *)r = *(int *)p + 1;
	return (r);
}

int		iTest = 1;
int	main(void)
{
	int		tab[] = {0, 1, 2, 3};
	t_list	*l;
	t_list	*m;
	t_list	*tmp;

	signal(SIGSEGV, sigsegv);
	title("ft_lstmap\t: ");
	l = ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	m = ft_lstmap(l, addOne, free);
	tmp = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int *)tmp->content == i);
		tmp = (t_list *)tmp->next;
	}
	tmp = m;
	/* 5 6 7 8 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int *)tmp->content == i + 1);
		tmp = (t_list *)tmp->next;
	}
	freeList(l);
	ft_lstclear(&m, free);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
