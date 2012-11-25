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
#include <QObject>

/*
***************************************************************
*
* constructor  
*
***************************************************************
*/
Sphere::Sphere(Point3D& centerLocation, double radius)
:I_GenericShape()
{
   center_ = centerLocation;
   radius_ = radius;
}

Sphere::~Sphere()
{

}

/*
***************************************************************
*
* returns a valid intersection if the ray intersects the sphere
* anywhere.  
*
***************************************************************
*/
Intersection Sphere::intersects(Ray& ray)
{
   Vector3D c(ray.startPoint(), center_);
   double cDotDirection = ray.directionVector().dotProduct(c);
   double value = (cDotDirection*cDotDirection) - (c.magnitude()*c.magnitude()) + (radius_*radius_);


   Intersection intersection;
   intersection.objectId = shapeId_;
   intersection.valid = false;
   intersection.distanceFromCamera = 0.0;
   if(value < 0)
   {
      return intersection;
   }
   double sqrtValue = sqrt(value);

   //One solution Exists
   if(qFuzzyCompare(1 + value, 1.0))
   {
      double distance = cDotDirection;
      fillIntersection(intersection, ray, distance);
   }
   //Two Solutions Exist
   else if(value > 0)
   {
      double distanceSolutionOne = cDotDirection + sqrtValue;
      double distanceSolutionTwo = cDotDirection - sqrtValue;

      Intersection one;
      Intersection two;
      fillIntersection(one, ray, distanceSolutionOne);
      fillIntersection(two, ray, distanceSolutionTwo);

      if(distanceSolutionOne > distanceSolutionTwo)
      {         
         intersection = two;
      }
      else
      {
         intersection = one;
      }


   }

   if(intersection.distanceFromCamera < 0.01)
   {
      intersection.valid = false;
   }
   return intersection;
}

/*
***************************************************************
*
* files the Intersection with data if the ray actually hits the sphere.  
*
***************************************************************
*/
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
   intersection.objectId = shapeId_;

   Vector3D normal(center_, intersectionPoint);
   normal.normalizeVector();
   intersection.normal = normal;
}
