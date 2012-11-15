/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Colour.h"

Colour::Colour(double red, double green, double blue)
{
   red_ = red;
   green_ = green;
   blue_ = blue;
}

Colour::~Colour()
{

}

double Colour::red() const
{
   return red_;
}

double Colour::green() const
{
   return green_;
}

double Colour::blue() const
{
   return blue_;
}

void Colour::setRed(double red)
{
   red_ = red;
}

void Colour::setGreen(double green)
{
   green_ = green;
}

void Colour::setBlue(double blue)
{
   blue_ = blue;
}
