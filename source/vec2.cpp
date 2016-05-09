#include "vec2.hpp"
#include <iostream>

Vec2::Vec2():
x{0},y{0}
{}

Vec2::Vec2(float x_,float y_):
x{x_},
y{y_}{}

//Aufgabe 2.3

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;
	
	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x;
	y -= v.y;
	
	return *this;
}

Vec2& Vec2::operator*=(float v)
{
	x *= v;
	y *= v;
	
	return *this;
}

Vec2& Vec2::operator/=(float v)
{
	if(v==0.0f)
	{
	std::cout<<"Durch 0 teilen? Da hat wohl jemand nicht in Mathe aufgepasst..."<<std::endl;
	}
	else    
	{	
		x /= v;
		y /= v;

	}	
	return *this;
}

//Aufgabe 2.4
Vec2 operator +( Vec2 const & u , Vec2 const & v )
{
	Vec2 w;
	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return w;
}

Vec2 operator -( Vec2 const & u , Vec2 const & v )
{
	Vec2 w;
	w.x = u.x - v.x;
	w.y = u.y - v.y;
	return w;
}

Vec2 operator *( Vec2 const & v , float s )
{
	Vec2 w;
	w.x = v.x * s;
	w.y = v.y * s;
	return w;
}

Vec2 operator /( Vec2 const & v , float s )
{
	Vec2 w;
	if(s==0.0f)
	{
		std::cout<<"Durch 0 teilen? Da hat wohl jemand nicht in Mathe aufgepasst..."<<std::endl;
	}
	else    
	{	
		w.x = v.x / s;
		w.y = v.y / s;
	
	}

	return w;
}

Vec2 operator *( float s , Vec2 const & v )
{
	Vec2 w;
	w.x = v.x * s;
	w.y = v.y * s;
	return w;
}







