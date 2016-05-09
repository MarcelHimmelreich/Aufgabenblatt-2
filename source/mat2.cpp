#include "mat2.hpp"
#include "vec2.hpp"
#include <iostream>
#include <math.h>

Mat2::Mat2():
a{1},
b{0},
c{0},
d{0}{}

Mat2::Mat2(float a_,float b_,float c_,float d_):
a{a_},
b{b_},
c{c_},
d{d_}{}

// Aufgabe 2.5

Mat2& Mat2::operator*=(Mat2 const& v)
{
	float atemp,btemp,ctemp,dtemp;

	atemp = a*v.a + b*v.c;
	btemp = a*v.b + b*v.d;
	ctemp = c*v.a + d*v.c;
	dtemp = c*v.b + d*v.d;

	a=atemp,b=btemp,c=ctemp,d=dtemp;
	
	return *this;
}
Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 )
{
	Mat2 r;
	r.a = m1.a*m2.a + m1.b*m2.c;
	r.b = m1.a*m2.b + m1.b*m2.d;
	r.c = m1.c*m2.a + m1.d*m2.c;
	r.d = m1.c*m2.b + m1.d*m2.d;

	return r;
}

//Aufgabe 2.6

Vec2 operator*( Mat2 const & m , Vec2 const & v )
{
	Vec2 e;
	e.x = m.a * v.x + m.b * v.y;
	e.y = m.c * v.x + m.d * v.y;
	return e;
}
Mat2 operator*( Mat2 const & m , float v )
{
	Mat2 n{m};
	n.a*=v;
	n.b*=v;
	n.c*=v;
	n.d*=v;
	return n;
}

Vec2 operator*( Vec2 const & v , Mat2 const & m )
{
	Vec2 r;
	r.x = m.a * v.x + m.c * v.y;
	r.y = m.b * v.x + m.d * v.y;
	return r;
}

float Mat2::det () const
{
	return a*d-c*b;
}

Mat2 inverse ( Mat2 const & m )
{
	float det=m.det();
	if(det== 0.0f )
	{
		std::cout<<"Oha. Det=0? Da hab wohl jemand nicht aufgepasst..."<<std::endl;
		return m;
	}
	else 
	{
		Mat2 n{m.d,-1*m.b,-1*m.c,m.a};
		return n*(1/det);	
	}
}

Mat2 transpose ( Mat2 const & m )
{
	Mat2 n{m.a,m.c,m.b,m.d};
	return n;
}

Mat2 make_rotation_mat2 ( float phi )
{
	float Newa=cos(phi);
	float Newb=-sin(phi);
	float Newc=sin(phi);
	float Newd=cos(phi);
	Mat2 a{Newa,Newb,Newc,Newd};
	return a;
}     




