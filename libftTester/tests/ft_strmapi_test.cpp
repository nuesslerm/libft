extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "check.hpp"
#include "leaks.hpp"
#include "sigsegv.hpp"
#include <climits>
#include <string.h>

char	addOne(unsigned int i, char c)
{
	return (i + c);
}

int		iTest = 1;
int	main(void)
{
	char	*s;

	signal(SIGSEGV, sigsegv);
	title("ft_strmapi\t: ");
	s = ft_strmapi("1234", addOne);
	/* 1 */ check(!strcmp(s, "1357"));
	/* 2 */ mcheck(s, strlen("1357") + 1);
	free(s);
	showLeaks();
	s = ft_strmapi("", addOne);
	/* 3 */ check(!strcmp(s, ""));
	/* 4 */ mcheck(s, strlen("") + 1);
	free(s);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
