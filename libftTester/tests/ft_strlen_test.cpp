extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "check.hpp"
#include "leaks.hpp"
#include "sigsegv.hpp"

int	iTest = 1;
int	main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_strlen\t: ");
	/* 1 */ check(ft_strlen("123") == 3);
	showLeaks();
	/* 2 */ check(ft_strlen("") == 0);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
