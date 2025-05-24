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
void	addOne(void *p)
{
	++*(int *)p;
}

int		iTest = 1;
int	main(void)
{
	int		tab[] = {0, 1, 2, 3};
	t_list	*l;
	t_list	*tmp;

	signal(SIGSEGV, sigsegv);
	title("ft_lstiter\t: ");
	l = ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	ft_lstiter(l, addOne);
	tmp = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int *)tmp->content == i + 1);
		tmp = (t_list *)tmp->next;
	}
	freeList(l);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
