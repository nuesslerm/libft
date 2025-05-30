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
	title("ft_putendl_fd\t: ");
	fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putendl_fd((char *)"42", fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 4);
	/* 1 */ check(!strcmp(s, "42\n"));
	showLeaks();
	close(fd);
	unlink("./tripouille");
	write(1, "\n", 1);
	return (0);
}
