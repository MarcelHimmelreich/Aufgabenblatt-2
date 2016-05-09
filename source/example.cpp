#include "window.hpp"
#include <utility>
#include <cmath>
#include <vector>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  auto t0 = win.get_time();

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    std::vector<Vec2> vec(4);
    std::vector<color> farb(5);
    std::vector<Circle> kreis(2);
    std::vector<Rectangle> rechteck(2);


	
	//Rechteck Schwarz
    vec[1]={0.3,0.3};
    farb[1]={0.0,0.0,0.0};
    rechteck[1]={vec[1],0.4,0.2,farb[1]};
    rechteck[1].draw(win);  
 
	//Kreis schwarz
    vec[3]={0.3,0.3};
    farb[3]={0.0,0.0,0.0};
    kreis[1]={0.1 ,vec[3],farb[3]};
    kreis[1].draw(win);   

	//Füllfarbe Schwarz    
    farb[0]={0,0,0};

    auto m = win.mouse_position();
    Vec2 mouse{m.first,m.second};

    for (unsigned int i=0;i<kreis.size();i++)
        {
            if(kreis[i].isInside(mouse) )
		{
			kreis[i].fill(win,farb[0]);
		}
        }
    for (unsigned int i=0;i<rechteck.size();i++)
        {
            if(rechteck[i].isInside(mouse) )
		{
			rechteck[i].fill(win,farb[0]);
			//rechteck[i].fill(win,farb[1])
		} 
       }


    win.update();
  }

  return 0;
}

//Rectangle(Vec2 v_, float w, float h, color farb_)
//Circle(float rad_, Vec2 v_,color farb_)
