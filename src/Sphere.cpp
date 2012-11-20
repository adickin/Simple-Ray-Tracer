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
:I_GenericShape()
{
   center_ = centerLocation;
   radius_ = radius;
}

Sphere::~Sphere()
{

}

Intersection Sphere::intersects(Ray& ray)
{
   Vector3D c(ray.startPoint(), center_);
   double cDotDirection = ray.directionVector().dotProduct(c);
   double value = (cDotDirection*cDotDirection) - (c.magnitude()*c.magnitude()) + (radius_*radius_);

   double sqrtValue = sqrt(value);

   Intersection intersection;
   intersection.objectId = shapeId_;
   intersection.valid = false;
   if(value < 0)
   {
      return intersection;
   }

   //One solution Exists
   if(value == 0)
   {
      double distance = cDotDirection;
      fillIntersection(intersection, ray, distance);
   }
   //Two Solutions Exist
   else if(value > 0)
   {
      double distanceSolutionOne = cDotDirection + sqrtValue;
      double distanceSolutionTwo = cDotDirection - sqrtValue;

      if(distanceSolutionOne < distanceSolutionTwo)
      {
         fillIntersection(intersection, ray, distanceSolutionOne);
      }
      else
      {
         fillIntersection(intersection, ray, distanceSolutionTwo);
      }
   }
   return intersection;
}

void Sphere::fillIntersection(Intersection& intersection, Ray& ray, double distance)
{
   Point3D intersectionPoint;
   intersectionPoint.setX(ray.startPoint().x() + ray.directionVector().x()*distance);
   intersectionPoint.setY(ray.startPoint().y() + ray.directionVector().y()*distance);
   intersectionPoint.setZ(ray.startPoint().z() + ray.directionVector().z()*distance);

   intersection.valid = true;
   intersection.rayFromCamera.setStartPoint(ray.startPoint());
   intersection.rayFromCamera.setDirectionVector(ray.directionVector());
   intersection.intersectionPointClosest = intersectionPoint;
   intersection.material = shapeMaterial_;
   intersection.distanceFromCamera = distance;

   Vector3D normal(intersectionPoint, center_);
   normal.normalizeVector();
   intersection.normal = normal;
}
