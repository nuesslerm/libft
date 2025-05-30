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

using namespace	std;

void			title(const char *s);
void			check(bool succes);
void			mcheck(void *p, size_t required_size);

#endif
