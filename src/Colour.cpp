
#include "Colour.h"

/*
***************************************************************
*
* Constructor  
*
***************************************************************
*/
Colour::Colour()
{
   red_ = 0;
   green_ = 0;
   blue_ = 0;
}

/*
***************************************************************
*
* Constructor  
*
***************************************************************
*/
Colour::Colour(double red, double green, double blue)
{
   red_ = red;
   green_ = green;
   blue_ = blue;
   clamp(red_);
   clamp(green_);
   clamp(blue_);
}

/*
***************************************************************
*
* destructor  
*
***************************************************************
*/
Colour::~Colour()
{

}

/*
***************************************************************
*
* Overloaded operator to allow for easy multiplication of colours  
*
***************************************************************
*/
Colour Colour::operator*(const Colour &rhs)
{
   Colour returnColour;
   returnColour.setRed(red_*rhs.red());
   returnColour.setGreen(green_*rhs.green());
   returnColour.setBlue(blue_*rhs.blue());
   return returnColour;
}

/*
***************************************************************
*
* Overloaded operator to allow for easy addition of colours  
*
***************************************************************
*/
Colour Colour::operator+(const Colour &rhs)
{
   Colour returnColour;
   returnColour.setRed(red_+rhs.red());
   returnColour.setGreen(green_+rhs.green());
   returnColour.setBlue(blue_+rhs.blue());
   return returnColour;
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
   clamp(red_);
}

void Colour::setGreen(double green)
{
   green_ = green;
   clamp(green_);
}

void Colour::setBlue(double blue)
{
   blue_ = blue;
   clamp(blue_);
}

void Colour::setColour(double red, double green, double blue)
{
   setRed(red);
   setGreen(green);
   setBlue(blue);
}

/*
***************************************************************
*
* Allows a colour to be multipled by a scalar value.  
*
***************************************************************
*/
void Colour::multiplyColourByConstant(double constant)
{
   setRed(red_ * constant);
   setGreen(green_ * constant);
   setBlue(blue_ * constant);
}

/*
***************************************************************
*
* clamps the \a colour to be between 0 and 1.0  
*
***************************************************************
*/
void Colour::clamp(double& colour)
{
   if(colour > 1.0)
   {
      colour = 1.0;
   }
   else if(colour < 0)
   {
      colour = 0.0;
   }
}
