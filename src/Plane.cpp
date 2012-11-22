/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Plane.h"
#include "math.h"
#include <QObject>

Plane::Plane(Point3D one, Point3D two, Point3D three)
   :I_GenericShape()
   ,one_(one)
   ,two_(two)
   ,three_(three)
{
   Vector3D tempOne(two_, one_);
   Vector3D tempTwo(three_, one_);

   normal_ = tempOne.crossProduct(tempTwo);
   normal_.normalizeVector();
}

Plane::~Plane()
{

}

Intersection Plane::intersects(Ray& ray)
{
   double lDotN = ray.directionVector().dotProduct(normal_);
   // Vector3D normal = normal_;
   // if(lDotN < 0.0)
   // {
   //    normal_.multiplyByConstant(-1);
   //    lDotN = ray.directionVector().dotProduct(normal_);
   // }
   Vector3D temp(ray.startPoint(), one_);
   double plDotN = temp.dotProduct(normal_);
   double distance = plDotN/lDotN;

   Intersection intersection;
   intersection.distanceFromCamera = 0.0;
   intersection.valid = false;
   intersection.objectId = shapeId_;
   if(distance > 0.01)
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

      intersection.normal = normal_;
   }

   return intersection;
}

void Plane::fillIntersection(Intersection& intersection,
                        Ray& ray, double distance)
{

}
