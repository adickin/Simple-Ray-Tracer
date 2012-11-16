/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "stdio.h"
#include "Point3D.h"

/*
***************************************************************
*
*  Class that acts as a vector in a 3d space
*
***************************************************************
*/
class Vector3D
{
public:
   Vector3D();
   Vector3D(double x, double y, double z);
   Vector3D(const Point3D& one, const Point3D& two);
   ~Vector3D();

   void crossProduct(const Vector3D* vector);
   double dotProduct(const Vector3D* vector);
   double magnitude();
   void normalizeVector();

   double x() const;
   double y() const;
   double z() const;

   void setX(double x);
   void setY(double y);
   void setZ(double z);

private:
   bool isUnitVector_;
   double x_;
   double y_;
   double z_;

};

#endif
