/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Triangle.h"

Triangle::Triangle(Point3D one, Point3D two, Point3D three)
:Plane(one, two, three)
{

}

Triangle::~Triangle()
{

}

Intersection Triangle::intersects(Ray& ray)
{
   Intersection intersectionWithPlane = Plane::intersects(ray);

   if(intersectionWithPlane.valid)
   {
      Vector3D one(intersectionWithPlane.intersectionPointClosest, one_);
      one.normalizeVector();
      Vector3D two(intersectionWithPlane.intersectionPointClosest, two_);
      two.normalizeVector();
      Vector3D three(intersectionWithPlane.intersectionPointClosest, three_);
      three.normalizeVector();

      Vector3D addedVector = one + two + three;
      if(addedVector.magnitude() > 1.0)
      {
         intersectionWithPlane.valid = false;
      }
   }

   return intersectionWithPlane;
}
