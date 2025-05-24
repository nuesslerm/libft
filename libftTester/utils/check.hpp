#ifndef CHECK_HPP
# define CHECK_HPP
# include "color.hpp"
# include <iostream>
# include <sstream>
# include <string>
# include <unistd.h>

# ifdef __unix__
#  include <malloc.h>
# endif
# ifdef __APPLE__
#  include <malloc/malloc.h>
#  include <stdlib.h>
# endif

void	title(const char *s)
{
	std::ostringstream ss;
	ss << FG_LGRAY << s;
	write(1, ss.str().c_str(), ss.str().size());
}
using namespace	std;

void			check(bool succes);
void			mcheck(void *p, size_t required_size);

#endif
