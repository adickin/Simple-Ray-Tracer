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

Plane::Plane()
:I_GenericShape()
{
   one_.setX(-20);
   one_.setY(0);
   one_.setZ(-150);

   two_.setX(0);
   two_.setY(-200);
   two_.setZ(-100);

   three_.setX(300);
   three_.setY(-200);
   three_.setZ(-100);

   Vector3D tempOne(two_, one_);
   Vector3D tempTwo(three_, one_);

   normal_ = tempOne.crossProduct(tempTwo);
   normal_.normalizeVector();
   d_ = 0 - normal_.x()*one_.x() - normal_.y()*one_.y() - normal_.z()*one_.z();
}

Plane::~Plane()
{

}

Intersection Plane::intersects(Ray& ray)
{
   double lDotN = ray.directionVector().dotProduct(normal_);
   Vector3D normal = normal_;
   if(lDotN < 0.0)
   {
      normal.multiplyByConstant(-1);
   }
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
