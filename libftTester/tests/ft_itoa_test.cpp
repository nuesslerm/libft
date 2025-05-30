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

int	iTest = 1;
int	main(void)
{
	char	*s;

	signal(SIGSEGV, sigsegv);
	title("ft_itoa\t\t: ");
	s = ft_itoa(INT_MAX);
	/* 1 */ check(!strcmp(s, to_string(INT_MAX).c_str()));
	/* 2 */ mcheck(s, strlen(to_string(INT_MAX).c_str()) + 1);
	free(s);
	showLeaks();
	s = ft_itoa(INT_MIN);
	/* 3 */ check(!strcmp(s, to_string(INT_MIN).c_str()));
	/* 4 */ mcheck(s, strlen(to_string(INT_MIN).c_str()) + 1);
	free(s);
	showLeaks();
	s = ft_itoa(0);
	/* 5 */ check(!strcmp(s, to_string(0).c_str()));
	/* 6 */ mcheck(s, strlen(to_string(0).c_str()) + 1);
	free(s);
	showLeaks();
	s = ft_itoa(1);
	/* 7 */ check(!strcmp(s, to_string(1).c_str()));
	/* 8 */ mcheck(s, strlen(to_string(1).c_str()) + 1);
	free(s);
	showLeaks();
	s = ft_itoa(-1);
	/* 9 */ check(!strcmp(s, to_string(-1).c_str()));
	/* 10 */ mcheck(s, strlen(to_string(-1).c_str()) + 1);
	free(s);
	showLeaks();
	s = ft_itoa(42);
	/* 11 */ check(!strcmp(s, to_string(42).c_str()));
	/* 12 */ mcheck(s, strlen(to_string(42).c_str()) + 1);
	free(s);
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
