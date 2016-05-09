#ifndef COLOR_HPP
#define COLOR_HPP


//Aufgabe 2.7

struct color{
color();
color(float r, float g , float b);

	float r;
	float g;
	float b;

color& operator=( color const& c );
};

#endif
