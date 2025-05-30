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

int	iTest = 1;
int	main(void)
{
	t_list	*l;

	signal(SIGSEGV, sigsegv);
	title("ft_lstnew\t: ");
	l = ft_lstnew((void *)42);
	/* 1 */ check(l->content == (void *)42);
	/* 2 */ check(l->next == 0);
	/* 3 */ mcheck(l, sizeof(t_list));
	free(l);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
