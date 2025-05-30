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
#include <unistd.h>

int	iTest = 1;
int	main(void)
{
	char	tab[100];
	int		i;

	signal(SIGSEGV, sigsegv);
	title("ft_memset\t: ");
	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	/* 1 */ check(tab[0] == 0);
	showLeaks();
	ft_memset(tab, 'A', 42);
	i = 0;
	for (; i < 100 && tab[i] == 'A'; ++i)
		;
	/* 2 */ check(i == 42 && tab[42] == 0);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
