/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
#include "Point3D.h"
class Ray
{
public:
   Ray();
   virtual ~Ray();

   void setStartPoint(const Point3D& point);
   void setDirectionVector(const Vector3D& vector);

   Point3D startPoint();
   Vector3D directionVector();

private:
   Vector3D direction_;
   Point3D startPoint_;
};

#endif