/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Plane.h"

class Triangle : public Plane
{
public:
   Triangle(Point3D one, Point3D two, Point3D three);
   ~Triangle();

   virtual Intersection intersects(Ray& ray);
};

#endif
