#ifndef LEAK_HPP
# define LEAK_HPP
# include "color.hpp"
# include <algorithm>
# include <dlfcn.h>
# include <iostream>
# include <sstream>
# include <stdlib.h>
# include <unistd.h>
# include <vector>

using std::endl;
struct		ptr
{
	void	*p;
	size_t	size;
	ptr(void *_p = 0, size_t _size = 0) : p(_p), size(_size)
	{
	}
};

bool operator==(ptr const &p1, ptr const &p2);

extern std::vector<ptr> mallocList;

void		mallocListAdd(void *p, size_t size);
void		mallocListRemove(void *p);
void		showLeaks(void);

#endif
