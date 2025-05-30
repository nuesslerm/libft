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

int		iTest = 1;
int	main(void)
{
	t_list	*l;

	signal(SIGSEGV, sigsegv);
	(void)iTest;
	title("ft_lstdelone\t: ");
	l = ft_lstnew(malloc(1));
	ft_lstdelone(l, free);
	l = 0;
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
