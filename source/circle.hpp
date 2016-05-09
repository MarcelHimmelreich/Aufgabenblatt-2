#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>

class Circle 
{
public:
Circle();
Circle(float rad, Vec2 v);
Circle(float rad, Vec2 v,color  farb);

void draw(Window& const& win);
void draw(Window& const&win,color c);
void set_radius(float r);      
float get_radius();            
float get_area();           
float get_circum();
float get_diameter();  
bool isInside(Vec2 const&v);

void fill(Window& win);
void fill(Window& win,color c); 

private:
float rad;
Vec2 v; 
color farb;    
};

#endif
