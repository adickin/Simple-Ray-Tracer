/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef COLOUR_H
#define COLOUR_H

class Colour
{
public:
   Colour();
   Colour(double red, double green, double blue);
   virtual ~Colour();
   Colour operator*(const Colour &rhs);
   Colour operator+(const Colour &rhs);

   double red() const;
   double green() const;
   double blue() const;

   void setRed(double red);
   void setGreen(double green);
   void setBlue(double blue);

   void multiplyColourByConstant(double constant);

private:
   void clamp(double& colour);
   double red_;
   double green_;
   double blue_;
};

#endif
