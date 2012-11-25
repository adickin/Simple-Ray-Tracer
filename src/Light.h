/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "Colour.h"
#include "I_GenericShape.h"
#include "Point3D.h"
#include "Vector3D.h"

/*
***************************************************************
*
*  class that defines a light in a scene.  Provides functions for
*  phong lighting.  Also has the phong lighting parts separated
*  so that each part of the light can be accessed separatly
*
***************************************************************
*/
class Light
{
public:
   Light(Point3D location, Colour colour);
   ~Light();

   Point3D location();

   Colour phongLighting(Intersection& intersection);
   Colour ambientLight(Intersection& intersection);
   Colour diffuseLight(Intersection& intersection);
   Colour specularLight(Intersection& intersection);

private:
   Point3D location_;
   Colour lightColour_;
};

#endif
