#include "color.hpp"

color::color():
r{0},
g{0},
b{0}{}

color::color(float r_,float g_,float b_):
r{r_},
g{g_},
b{b_}{}

color& color::operator=(color const& c)
{
	r=c.r;
	b=c.b;
	g=c.g;
	return *this;
}
