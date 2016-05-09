#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
public:

Rectangle();
Rectangle(Vec2 v);
Rectangle(Vec2 v, float width, float height);
Rectangle(Vec2 v, float width, float height, color farb);

void set_height(float l);
void set_width(float w);
float get_height();
float get_width();
float get_perimeter();
float get_area();
void draw(Window& win);
void draw(Window& win, color c);
bool isInside(Vec2 w);
void fill(Window& win);
void fill(Window& win, color c);


private:
Vec2 v;
float height; 
float width;			
color farb;

};
#endif
