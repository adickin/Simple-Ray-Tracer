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

#include "Vector3D.h"
#include "Point3D.h"
#include "Colour.h"
#include "I_GenericShape.h"
class Light
{
public:
   Light(Point3D location, Colour colour);
   ~Light();

   Colour phongLighting(Intersection& intersection);

private:
   Point3D location_;
   Colour lightColour_;
};

#endif