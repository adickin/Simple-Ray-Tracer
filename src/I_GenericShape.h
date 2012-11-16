/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef I_GENERICSHAPE_H
#define I_GENERICSHAPE_H

#include "Colour.h"

#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"


struct Material
{
   double specularReflection;
   double diffuseReflection;
   double ambientReflection;
   double shinyness;
   Colour colour;
};

struct Intersection
{
   bool valid;
   Ray rayFromCamera;
   Vector3D normal;

   Point3D intersectionPointClosest;


   Material material;
};


class I_GenericShape
{

public:
   I_GenericShape();
   ~I_GenericShape();

   Colour colour();
   void setColour(Colour& colour);

   double quadraticFormula(double b, double a, double c);

   virtual Intersection intersects(Ray* ray) = 0;

protected:
   Material shapeMaterial_;
};

#endif
