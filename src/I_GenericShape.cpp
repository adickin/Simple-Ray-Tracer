/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "I_GenericShape.h"
#include "math.h"

I_GenericShape::I_GenericShape()
{
   shapeMaterial_.colour.setBlue(0);
   shapeMaterial_.colour.setRed(0);
   shapeMaterial_.colour.setGreen(1.0);

   
   shapeMaterial_.ambientReflection = 2;
   shapeMaterial_.diffuseReflection = 3;
   shapeMaterial_.specularReflection = 5;
}

I_GenericShape::~I_GenericShape()
{

}

Colour I_GenericShape::colour()
{
   return shapeMaterial_.colour;
}

void I_GenericShape::setColour(Colour& colour)
{
   shapeMaterial_.colour = colour;
}

/*
***************************************************************
*
*   Does the quadratic formula, returns the smallest value calculated
*   unless it is negative.
*
***************************************************************
*/
double quadraticFormula(double b, double a, double c)
{
   double plusT = (-b + sqrt((b*b) + (4*a*c)))/(2*a);
   double negativeT = (-b - sqrt((b*b) + (4*a*c)))/(2*a);

   if(plusT < 0)
   {
      if(negativeT > 0)
      {
         return negativeT;
      }
   }
   else if(negativeT < 0)
   {
      if(plusT > 0)
      {
         return plusT;
      }
   }
   else if(plusT > negativeT)
   {
      return negativeT;
   }
   else if(negativeT > plusT)
   {
      return plusT;
   }

   return -1;
   

}