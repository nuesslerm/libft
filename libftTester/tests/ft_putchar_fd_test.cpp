extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "check.hpp"
#include "leaks.hpp"
#include "sigsegv.hpp"
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int	iTest = 1;
int	main(void)
{
	int		fd;
	char	s[10] = {0};

	signal(SIGSEGV, sigsegv);
	title("ft_putchar_fd\t: ");
	fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 2);
	/* 1 */ check(!strcmp(s, "a"));
	showLeaks();
	close(fd);
	unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
}
