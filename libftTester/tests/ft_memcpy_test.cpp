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
	char	dest[100];
	char	*rtn;
	char	src[] = {0, 0};
	int		i;

	signal(SIGSEGV, sigsegv);
	title("ft_memcpy\t: ");
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	/* 1 */ check(dest[0] == 'A');
	showLeaks();
	rtn = (char *)ft_memcpy(dest, NULL, 0);
	/* 2 */ check(rtn == dest && dest[0] == 'A');
	showLeaks();
	ft_memcpy(dest, src, 2);
	i = 0;
	for (; i < 100 && dest[i] == 0; ++i)
		;
	/* 3 */ check(i == 2 && dest[2] == 'A');
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
