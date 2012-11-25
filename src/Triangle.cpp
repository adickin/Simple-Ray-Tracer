/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Triangle.h"

/*
***************************************************************
*
* constructor.  extends plane since a triangle is a plane that is
* bounded between 3 points.
*
***************************************************************
*/
Triangle::Triangle(Point3D one, Point3D two, Point3D three)
:Plane(one, two, three)
{

}

Triangle::~Triangle()
{

}

/*
***************************************************************
*
* Returns a valid intersection if the ray hits the part of the plane that
* the triangle is occupying.  
*
***************************************************************
*/
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
