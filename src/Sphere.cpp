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

Intersection Sphere::intersects(Ray* ray)
{
   Vector3D c(ray->startPoint(), center_);
   double cDotDirection = ray->directionVector().dotProduct(&c);
   double value = cDotDirection*cDotDirection - c.magnitude()*c.magnitude() + radius_*radius_;
   double sqrtValue = sqrt(value);

   Intersection intersection;
   intersection.valid = false;
   //One solution Exists
   if(sqrtValue == 0)
   {
      double distance = cDotDirection;

      Point3D intersectionPoint;
      intersectionPoint.setX(ray->startPoint().x() + ray->directionVector().x()*distance);
      intersectionPoint.setY(ray->startPoint().y() + ray->directionVector().y()*distance);
      intersectionPoint.setZ(ray->startPoint().z() + ray->directionVector().z()*distance);

      intersection.valid = true;
      intersection.rayFromCamera = *ray;
      intersection.intersectionPointClosest = intersectionPoint;
      intersection.material = shapeMaterial_;

      //N = ((x - cx)/R, (y - cy)/R, (z - cz)/R)

      Vector3D normal;
      normal.setX( (intersectionPoint.x() - center_.x()) / radius_);
      normal.setY( (intersectionPoint.y() - center_.y()) / radius_);
      normal.setZ( (intersectionPoint.z() - center_.z()) / radius_);
      intersection.normal = normal;

      return intersection;
   }
   //Two Solutions Exist
   else if(sqrtValue > 0)
   {
      double distanceSolutionOne = cDotDirection + sqrtValue;
      double distanceSolutionTwo = cDotDirection - sqrtValue;

      if(distanceSolutionOne < distanceSolutionTwo)
      {
         Point3D intersectionPoint;
         intersectionPoint.setX(ray->startPoint().x() + ray->directionVector().x()*distanceSolutionOne);
         intersectionPoint.setY(ray->startPoint().y() + ray->directionVector().y()*distanceSolutionOne);
         intersectionPoint.setZ(ray->startPoint().z() + ray->directionVector().z()*distanceSolutionOne);

         intersection.valid = true;
         intersection.rayFromCamera = *ray;
         intersection.intersectionPointClosest = intersectionPoint;
         intersection.material = shapeMaterial_;

          //N = ((x - cx)/R, (y - cy)/R, (z - cz)/R)

         Vector3D normal;
         normal.setX( (intersectionPoint.x() - center_.x()) / radius_);
         normal.setY( (intersectionPoint.y() - center_.y()) / radius_);
         normal.setZ( (intersectionPoint.z() - center_.z()) / radius_);
         intersection.normal = normal;
      }
      else
      {
         Point3D intersectionPoint;
         intersectionPoint.setX(ray->startPoint().x() + ray->directionVector().x()*distanceSolutionTwo);
         intersectionPoint.setY(ray->startPoint().y() + ray->directionVector().y()*distanceSolutionTwo);
         intersectionPoint.setZ(ray->startPoint().z() + ray->directionVector().z()*distanceSolutionTwo);

         intersection.valid = true;
         intersection.rayFromCamera = *ray;
         intersection.intersectionPointClosest = intersectionPoint;
         intersection.material = shapeMaterial_;

         //N = ((x - cx)/R, (y - cy)/R, (z - cz)/R)

         Vector3D normal;
         normal.setX( (intersectionPoint.x() - center_.x()) / radius_);
         normal.setY( (intersectionPoint.y() - center_.y()) / radius_);
         normal.setZ( (intersectionPoint.z() - center_.z()) / radius_);
         intersection.normal = normal;
      }
      return intersection;
   }

   return intersection;
}
