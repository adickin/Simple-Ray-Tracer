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
   Triangle();
   ~Triangle();

   virtual Intersection intersects(Ray& ray);
};

#endif
