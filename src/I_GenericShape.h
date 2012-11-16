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

class Point3D;
class Vector3D;
class Ray;

class I_GenericShape
{

public:
   I_GenericShape();
   ~I_GenericShape();

   double quadraticFormula(double b, double a, double c);

   virtual bool intersects(Ray* ray) = 0;
};

#endif
