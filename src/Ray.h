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
   void setFromObjectId(int objectId);
   void setInsideObject(bool inside);
   void setRefractionIndex(double refractionIndex);

   Point3D startPoint();
   Vector3D directionVector();
   int fromObjectId();
   bool insideObject();
   double refractionIndex();

   bool valid;

private:
   Vector3D direction_;
   Point3D startPoint_;
   int fromObjectId_;
   int insideObject_;
   double refractionIndex_;


};

#endif