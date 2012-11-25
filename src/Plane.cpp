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

/*
***************************************************************
*
* Constructor for a plane.  
*
***************************************************************
*/
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

/*
***************************************************************
*
* Function that determines if a ray intersects the plane.  If it
* intersects then it returns a Intersection that is valid.  
*
***************************************************************
*/
Intersection Plane::intersects(Ray& ray)
{
   double lDotN = ray.directionVector().dotProduct(normal_);
   Vector3D temp(ray.startPoint(), one_);
   double plDotN = temp.dotProduct(normal_);
   double distance = plDotN/lDotN;

   Intersection intersection;
   intersection.distanceFromCamera = 0.0;
   intersection.valid = false;
   intersection.objectId = shapeId_;
   if(distance > 0.00001)
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
