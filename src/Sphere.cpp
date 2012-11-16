/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Sphere.h"
#include "math.h"

Sphere::Sphere(Point3D& centerLocation, double radius)
{
   center_ = centerLocation;
   radius_ = radius;
}

Sphere::~Sphere()
{

}

bool Sphere::intersects(Ray* ray)
{
   Vector3D c(ray->startPoint(), center_);
   double cDotDirection = ray->directionVector().dotProduct(&c);

   double value = cDotDirection*cDotDirection - c.magnitude()*c.magnitude() + radius_*radius_;

   double sqrtValue = sqrt(value);

   if(sqrtValue >= 0)
   {
      return true;
   }
   else
   {
      return false;
   }
   return false;
}
