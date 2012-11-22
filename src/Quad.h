/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef QUAD_H
#define QUAD_H

#include "I_GenericShape.h"
#include "Triangle.h"

class Quad : public I_GenericShape
{
public:
   Quad(Point3D one, Point3D two, Point3D three, Point3D four);
   ~Quad();

   virtual Intersection intersects(Ray& ray);

private:
   Triangle triangleOne_;
   Triangle triangleTwo_;
};

#endif
