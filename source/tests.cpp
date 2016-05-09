#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"


//Aufgabe 2.3

TEST_CASE("describe_Vec2_Plus","[Vec2]")
{

Vec2 v1{1,2};
Vec2 v2{2.5,4.5};
Vec2 v3{-4,-6};

v1+=v1;
REQUIRE(v1.x == 2);
REQUIRE(v1.y == 4);

v3+=v1;
REQUIRE(v3.x == -2.0f);
REQUIRE(v3.y == -2.0f);

v2+=v3;
REQUIRE(v2.x == Approx(0.5f));
REQUIRE(v2.y == Approx(2.5f));

}
TEST_CASE("describe_Vec2_Minus","[Vec2]")
{

Vec2 v1{1,2};
Vec2 v3{4,1};
Vec2 v4{-2,2};
Vec2 v6{1.5,1.5};

v1-=v1;
REQUIRE(v1.x == 0);
REQUIRE(v1.y == 0);

v3-=v4;
REQUIRE(v3.x == 6);
REQUIRE(v3.y == -1);

v6-=v4;
REQUIRE(v6.x == Approx(3.5f));
REQUIRE(v6.y == Approx(-0.5f));


}

TEST_CASE("describe_Vec2_Mal","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v4{-2,-4};
Vec2 v6{1.5,2.3};

v1*=1.0;
REQUIRE(v1.x == Approx(1.0f));
REQUIRE(v1.y == Approx(2.0f));

v4*=2.0;
REQUIRE(v4.x == Approx(-4.0f));
REQUIRE(v4.y == Approx(-8.0f));

v6*=3.0;
REQUIRE(v6.x == Approx(4.5f));
REQUIRE(v6.y == Approx(6.9f));
}

TEST_CASE("describe_Vec2_Durch","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v4{-2,-4};
Vec2 v6{1.5,3.0};

v1/=3.0;
REQUIRE(v1.x == Approx(0.33333f));
REQUIRE(v1.y == Approx(0.66666f));

v4/=-1.0;
REQUIRE(v4.x == Approx(2.0f));
REQUIRE(v4.y == Approx(4.0f));

v6/=1.5;
REQUIRE(v6.x == Approx(1.0f));
REQUIRE(v6.y == Approx(2.0f));

}

//Aufgabe 2.4

TEST_CASE("describe_Vec2_Add","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v2{2,2};
Vec2 v3=v1+v2;
Vec2 v4{0,3};
Vec2 v5=v3+v4;
Vec2 v6{-2,-1};
Vec2 v7=v1+v6;
Vec2 v8{0.5,0.333};
Vec2 v9=v4+v8;

REQUIRE(v3.x==3);
REQUIRE(v3.y==4);

REQUIRE(v5.x==3);
REQUIRE(v5.y==7);

REQUIRE(v7.x==-1);
REQUIRE(v7.y==1);

REQUIRE(v9.x==Approx(0.5f));
REQUIRE(v9.y==Approx(3.333f));
}

TEST_CASE("describe_Vec2_Sub","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v2{2,2};
Vec2 v3=v1-v2;
Vec2 v4{0,3};
Vec2 v5=v3-v4;
Vec2 v6{-2,-1};
Vec2 v7=v1-v6;
Vec2 v8{0.5,0.333};
Vec2 v9=v4-v8;

REQUIRE(v3.x==-1);
REQUIRE(v3.y==0);

REQUIRE(v5.x==-1);
REQUIRE(v5.y==-3);

REQUIRE(v7.x==3);
REQUIRE(v7.y==3);

REQUIRE(v9.x==Approx(-0.5f));
REQUIRE(v9.y==Approx(2.667f));
}

TEST_CASE("describe_Vec2_Mul","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v2=v1*1.0;
Vec2 v3=v1*0.1;
Vec2 v4{0,3};
Vec2 v5=v4*4; 
Vec2 v6{-2,-1};
Vec2 v7=v6*(-2);
Vec2 v8{0.5,0.333};
Vec2 v9=v8*2;

REQUIRE(v2.x==Approx(1.0f));
REQUIRE(v2.y==Approx(2.0f));

REQUIRE(v3.x==Approx(0.10f));
REQUIRE(v3.y==Approx(0.20f));

REQUIRE(v5.x==Approx(0.0f));
REQUIRE(v5.y==Approx(12.0f));

REQUIRE(v7.x==Approx(4.0f));
REQUIRE(v7.y==Approx(2.0f));

REQUIRE(v9.x==Approx(1.0f));
REQUIRE(v9.y==Approx(0.666f));
}

TEST_CASE("describe_Vec2_Div","[Vec2]")
{
Vec2 v1{1,2};
Vec2 v2=v1/1.0;
Vec2 v3=v1/0.1;
Vec2 v4{0,3};
Vec2 v5=v4/4; 
Vec2 v6{-2,-1};
Vec2 v7=v6/(-2);
Vec2 v8{0.5,0.333};
Vec2 v9=v8/2;

REQUIRE(v2.x==Approx(1.0f));
REQUIRE(v2.y==Approx(2.0f));

REQUIRE(v3.x==Approx(10.0f));
REQUIRE(v3.y==Approx(20.0f));

REQUIRE(v5.x==Approx(0.0f));
REQUIRE(v5.y==Approx(0.75f));

REQUIRE(v7.x==Approx(1.0f));
REQUIRE(v7.y==Approx(0.5f));

REQUIRE(v9.x==Approx(0.25f));
REQUIRE(v9.y==Approx(0.1665f));
}


//Aufgabe 2.5
TEST_CASE("describe_Mat2_Durch","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,8,6};
Mat2 m3{};
Mat2 m4{-3,-4,-1,0};
Mat2 m5{0.5,1.5,1.33,-7.5};

m1*=m2;
REQUIRE(m1.a==19);
REQUIRE(m1.b==13);
REQUIRE(m1.c==41);
REQUIRE(m1.d==27);
m2*=m3;
REQUIRE(m2.a==3);
REQUIRE(m2.b==0);
REQUIRE(m2.c==8);
REQUIRE(m2.d==0);
m4*=m2;
REQUIRE(m4.a==-41);
REQUIRE(m4.b==-0);
REQUIRE(m4.c==-3);
REQUIRE(m4.d==-0);
m2*=m5;
REQUIRE(m2.a==Approx(1.5f));
REQUIRE(m2.b==Approx(4.5f));
REQUIRE(m2.c==Approx(4.0f));
REQUIRE(m2.d==Approx(12.0f));

}

TEST_CASE("describe_Mat2_Div","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,8,6};
Mat2 m3{};
Mat2 m4{-3,-4,-1,0};
Mat2 m5{0.5,1.5,1.33,-7.5};
Mat2 m6=m1*m2;
Mat2 m7=m2*m3;
Mat2 m8=m4*m2;
Mat2 m9=m2*m5;

REQUIRE(m6.a==19);
REQUIRE(m6.b==13);
REQUIRE(m6.c==41);
REQUIRE(m6.d==27);

REQUIRE(m7.a==3);
REQUIRE(m7.b==0);
REQUIRE(m7.c==8);
REQUIRE(m7.d==0);

REQUIRE(m8.a==-41);
REQUIRE(m8.b==-27);
REQUIRE(m8.c==-3);
REQUIRE(m8.d==-1);

REQUIRE(m9.a==Approx(2.83f));
REQUIRE(m9.b==Approx(-3.0f));
REQUIRE(m9.c==Approx(11.98f));
REQUIRE(m9.d==Approx(-33.0f));
}

TEST_CASE("describe_Mat2_MatVek","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,-8,6};
Mat2 m3{};
Mat2 m4{0.3,-4.1,7.5,0};

Vec2 v1{2,4};
Vec2 v2{-1,1};
Vec2 v3{3.33,5.9};

Vec2 v4,v5,v6,v7;

v4 = v1*m3;
REQUIRE(v4.x==2);
REQUIRE(v4.y==0);

v5 = v1*m1;
REQUIRE(v5.x==14);
REQUIRE(v5.y==20);

v6 = m2*v2;
REQUIRE(v6.x==-2);
REQUIRE(v6.y==14);

v7 = v3*m4;
REQUIRE(v7.x==Approx(45.249f));
REQUIRE(v7.y==Approx(-13.653f));
}
TEST_CASE("describe_Mat2_Det","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,-8,6};
Mat2 m3{};
Mat2 m4{0.3,-4.1,7.5,0};

REQUIRE(m1.det() == -2);
REQUIRE(m2.det() == 26);
REQUIRE(m3.det() == 0);
REQUIRE(m4.det() == Approx(30.75));
}

TEST_CASE("describe_Mat2_Inv","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,-8,6};
Mat2 m3{};
Mat2 m4{0.3,-4.1,7.5,0};

Mat2 m5 =inverse(m1);
REQUIRE(m5.a == -2);
REQUIRE(m5.b == 1);
REQUIRE(m5.c == Approx(1.5));
REQUIRE(m5.d == Approx(-0.5)); 

Mat2 m6 =inverse(m2);
REQUIRE(m6.a == Approx(0.23077));
REQUIRE(m6.b == Approx(-0.03846));
REQUIRE(m6.c == Approx(0.30769));
REQUIRE(m6.d == Approx(0.11538));

Mat2 m7 =inverse(m3);
REQUIRE(m7.a == 1);
REQUIRE(m7.b == 0);
REQUIRE(m7.c == 0);
REQUIRE(m7.d == 0);

Mat2 m8 =inverse(m4);
REQUIRE(m8.a == 0);
REQUIRE(m8.b == Approx(0.133333));
REQUIRE(m8.c == Approx(-0.243902));
REQUIRE(m8.d == Approx(0.009756));
}

TEST_CASE("describe_Mat2_Tra","[Mat2]")
{
Mat2 m1{1,2,3,4};
Mat2 m2{3,1,-8,6};
Mat2 m3{};
Mat2 m4{0.3,-4.1,7.5,0};

Mat2 m5 =transpose(m1);
REQUIRE(m5.a == 1);
REQUIRE(m5.b == 3);
REQUIRE(m5.c == 2);
REQUIRE(m5.d == 4); 

Mat2 m6 =transpose(m2);
REQUIRE(m6.a == 3 );
REQUIRE(m6.b == -8);
REQUIRE(m6.c == 1 );
REQUIRE(m6.d == 6 );

Mat2 m7 =transpose(m3);
REQUIRE(m7.a == 1);
REQUIRE(m7.b == 0);
REQUIRE(m7.c == 0);
REQUIRE(m7.d == 0);

Mat2 m8 =transpose(m4);
REQUIRE(m8.a == Approx(0.3));
REQUIRE(m8.b == Approx(7.5));
REQUIRE(m8.c == Approx(-4.1));
REQUIRE(m8.d == 0);
}

TEST_CASE("describe_Mat2_Rot","[Mat2]")
{
Mat2 m5 = make_rotation_mat2 ( M_PI );
Mat2 m6 = make_rotation_mat2 ( 1 );
Mat2 m7 = make_rotation_mat2 ( 0 );
Mat2 m8 = make_rotation_mat2 ( 2.5 );

REQUIRE(m5.a == -1);
REQUIRE(m5.b == Approx(0.0));
REQUIRE(m5.c == Approx(0.0));
REQUIRE(m5.d == -1); 

REQUIRE(m6.a == Approx(0.540302) );
REQUIRE(m6.b == Approx(-0.841471));
REQUIRE(m6.c == Approx(0.841471) );
REQUIRE(m6.d == Approx(0.540302) );

REQUIRE(m7.a == 1);
REQUIRE(m7.b == 0);
REQUIRE(m7.c == 0);
REQUIRE(m7.d == 1);

REQUIRE(m8.a == Approx(-0.801144));
REQUIRE(m8.b == Approx(-0.598472));
REQUIRE(m8.c == Approx( 0.598472));
REQUIRE(m8.d == Approx(-0.801144));
}


TEST_CASE("describe_Circle","[Circle]")
{
Vec2 v{100,200};
Circle kreis{20,v};

REQUIRE(kreis.get_radius() == 20);
REQUIRE(kreis.get_diameter()  == 40);
REQUIRE(kreis.get_area() ==Approx(1256.6368));
REQUIRE(kreis.get_circum() == Approx(125.66368)); 
kreis.set_radius(2.22);
REQUIRE(kreis.get_radius() == Approx(2.22));
}



TEST_CASE("describe_Rect","[Rectangle]")
{
Vec2 v{300,500};
Rectangle eck{v,43,65};

REQUIRE(eck.get_height() == 65);
REQUIRE(eck.get_width()  == 43);
REQUIRE(eck.get_perimeter() == 216);
REQUIRE(eck.get_area() == 2795); 
eck.set_height(5.34);
eck.set_width(4.36);
REQUIRE(eck.get_height() == Approx(5.34));
REQUIRE(eck.get_width()  == Approx(4.36));
}

TEST_CASE("describe_Risinside","[Rectangle]")
{
Vec2 v0{0.0,0.0};
Vec2 v25{0.25,0.25};
Vec2 v5{0.5,0.5};
Vec2 v10{1.0,1.0};
Rectangle eck{v25,0.5,0.5};

REQUIRE(eck.isInside(v0) == false);
REQUIRE(eck.isInside(v25) == true);
REQUIRE(eck.isInside(v5) == true);
REQUIRE(eck.isInside(v10) == false);

}
TEST_CASE("describe_Cisinside","[Circle]")
{
Vec2 v0{0.0,0.0};
Vec2 v25{0.25,0.25};
Vec2 v5{0.5,0.5};
Vec2 v10{1.0,1.0};
Circle kreis{0.4,v5};

REQUIRE(kreis.isInside(v0) == false);
REQUIRE(kreis.isInside(v25) == true);
REQUIRE(kreis.isInside(v5) == true);
REQUIRE(kreis.isInside(v10) == false);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
