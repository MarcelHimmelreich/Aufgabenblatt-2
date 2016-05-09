#include <utility>
#include <cmath>
#include <vector>
#include <iostream>
#include "window.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(1000,1000)};
  auto t0 = win.get_time();
    


  while (!win.should_close()) 
{
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) 
	{	
      		win.close();
	}
	 
	auto t = win.get_time();

	//Zeit quantisieren
    int quant=t;
    double sek=quant;
    double min=quant/60;
    double hour=quant/3600;

    int i=0;
    float winkel=0;

    Vec2 m_Punkt={0.5,0.5};
    color cRound={0.0f,0.0f,0.0f};
    Circle rahmen ={0.45,m_Punkt,cRound};
    rahmen.draw(win);   

    winkel=M_PI*2/60;

    win.draw_line(0.5,0.5,0.5+sin(winkel*sek)*0.4,0.5+cos(winkel*sek)*0.4,0.0f,0.0f,0.0f); //Sekundenzeiger
    win.draw_line(0.5,0.5,0.5+sin(winkel*min)*0.2,0.5+cos(winkel*min)*0.2,0.0f,0.0f,0.0f); //Minutenzeiger
    win.draw_line(0.5,0.5,0.5+sin(winkel*hour)*0.1,0.5+cos(winkel*hour)*0.1,0.0f,0.0f,0.0f); //Stundenzeiger

    win.update();
 }

  return 0;
}
