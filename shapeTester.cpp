#include <iostream>
#include <math.h>

using namespace std;
string input;
double PI = 3.141592653589793;

int x = 0;
bool running = true;

class Box
{
public:
 void setLength(double len);
  void setWidth(double wid);
  void setHeight(double hei);
  double getVolume(void);
  double getSurface(void);
  Box();
private:
  double length;
  double width;
  double height;

};
Box::Box(void)
{

}

void Box::setLength(double l)
{
  length = l;
}

void Box::setWidth(double w)
{
  width = w;
}

void Box::setHeight(double h)
{
  height = h;
}

double Box::getVolume(void)
{
  double volume = width * length * height;
  return volume;
}

double Box::getSurface(void)
{
  double surface = 2 * ((width * length) + (height * length) + (height * width));
  return surface;
}

class Pyramid
{
public:
  void setLength(double l);
   void setWidth(double w);
   void setHeight(double h);
   double getVolume(void);
   double getSurface(void);
   void setSlantL(void);
   void setSlantW(void);
   Pyramid();
 private:
   double length;
   double width;
   double height;
   double slantW;
   double slantL;
};

Pyramid::Pyramid(void)
{

}

void Pyramid::setLength(double l)
{
  length = l;
}

void Pyramid::setWidth(double w)
{
  width = w;
}

void Pyramid::setHeight(double h)
{
  height = h;
}

void Pyramid::setSlantW()
{
  slantW = sqrt(pow((length/2),2) + pow(height,2));
}
void Pyramid::setSlantL()
{
  slantL = sqrt(pow((width/2),2) + pow(height,2));
}

double Pyramid::getVolume(void)
{
  double volume = (length * width * height) / 3;
  return volume;
}
double Pyramid::getSurface(void)
{
  double surface = (length * width) + (2*(0.5 * (slantL * length))) + (2*(0.5 * slantW * width)) ;
  return surface;
}



class Sphere
{
public:
 void setRadius(double r);
 double getVolume(void);
 double getSurface(void);
  Sphere();
private:
  double radius;
};
Sphere::Sphere(void)
{

}
void Sphere::setRadius(double r)
{
  radius = r;
}

double Sphere::getVolume(void)
{
  double volume = (1.33333333333 * PI * (radius * radius * radius));
  return volume;
}

double Sphere::getSurface(void)
{
  double surface = 4 * PI * (radius * radius);
  return surface;
}

int main()
{
  while (running)
   {


  cout << "Pick a shape to calculate: Box - b, Sphere - s, or Pyramid - p" << endl;
  cin >> input;
  if (input == "b")
  {
    Box myBox;
    cout << "Box Length: ";
    cin >> x;
    myBox.setLength(x);
    cout << "Box Width: ";
    cin >> x;
    myBox.setWidth(x);
    cout << "Box Height: ";
    cin >> x;
    myBox.setHeight(x);
    cout << "Box Volume: " << myBox.getVolume() << endl;
    cout << "Box Surface Area: " << myBox.getSurface() << endl;
  } else if (input == "s")
  {
    Sphere mySphere;
    cout << "Sphere Radius: ";
    cin >> x;
    mySphere.setRadius(x);
    cout << "Sphere Volume: " << mySphere.getVolume() << endl;
    cout << "Sphere Surface Area: " << mySphere.getSurface() << endl;

  } else if (input == "p")
  {
    Pyramid myPyramid;
    cout << "Pyramid Length: ";
    cin >> x;
    myPyramid.setLength(x);
    cout << "Pyramid Width: ";
    cin >> x;
    myPyramid.setWidth(x);
    cout << "Pyramid Height: ";
    cin >> x;
    myPyramid.setHeight(x);
    myPyramid.setSlantL();
    myPyramid.setSlantW();
    cout << "Pyramid Volume: " << myPyramid.getVolume() << endl;
    cout << "Pyramid Surface Area: " << myPyramid.getSurface() << endl;
  } else
  {
    cout << "That shape is not supported. Try again!";
  }
}
}
