#include "circle.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include <math.h>
#include <iostream>

Circle::Circle():
rad{100},v{100,100},farb{}{}

Circle::Circle(float rad_, Vec2 v_):
rad{rad_},v{v_},farb{}{}

Circle::Circle(float rad_, Vec2 v_,color farb_):
rad{rad_},v{v_},farb{farb_}{}


void Circle::set_radius(float r) //Radius
{
	if(r ==0.0f)
	{
		rad = 1.0f;
	}
	else
	{
		rad=r;
	}
}      

float Circle::get_radius() //Radius
{
	return rad;
}          

float Circle::get_area() //Fläche
{
	return 3.141592*rad*rad;
}      

float Circle::get_circum() //Umfang
{
	return 3.141592*rad*2;
}

float Circle::get_diameter() //Durchmesser
{
	return 2*rad;
}

bool Circle::isInside(Vec2 w)
{
	if(sqrt((w.x-v.x)*(w.x-v.x) + (w.y-v.y)*(w.y-v.y))<rad )
		{
			return true;
		}
	else 
	{
		return false;
	}
}

void Circle::draw(Window& win) 
{
	for(float i=0.0;i<2*M_PI;i+=0.001)
	{
		win.draw_point(v.x+rad*cos(i), v.y+rad*sin(i), farb.r, farb.g, farb.b);
	}
}

void Circle::draw(Window& win, color c) 
{
	for(float i=0.0;i<2*M_PI;i+=0.001)
	{
		win.draw_point(v.x+rad*cos(i), v.y+rad*sin(i), c.r, c.g, c.b);
	}
}

void Circle::fill(Window& win) 
{
	for(float y=-rad;y<rad;y+=0.001)
	{
		for(float x=-rad;x<rad;x+=0.001)
		{
			if(sqrt(x*x+y*y)<rad )win.draw_point(x+v.x, y+v.y, farb.r, farb.g, farb.b);
		}
	}
	for(float i=0.0;i<2*M_PI;i+=0.001)
	{
		win.draw_point(v.x+rad*cos(i), v.y+rad*sin(i), farb.r, farb.g, farb.b);
	}	
}

void Circle::fill(Window& win, color c) 
{
	for(float y=-rad;y<rad;y+=0.001)
	{
		for(float x=-rad;x<rad;x+=0.001)
		{
			if(sqrt(x*x+y*y)<rad )
			{
				win.draw_point(x+v.x, y+v.y, c.r, c.g, c.b);
			}
		}
	}
	for(float i=0.0;i<2*M_PI;i+=0.001)
	{
		win.draw_point(v.x+rad*cos(i), v.y+rad*sin(i), c.r, c.g, c.b);
	}	
}
