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
   Colour(double red, double green, double blue);
   ~Colour();

   double red() const;
   double green() const;
   double blue() const;

   void setRed(double red);
   void setGreen(double green);
   void setBlue(double blue);

private:
   double red_;
   double green_;
   double blue_;
};

#endif
