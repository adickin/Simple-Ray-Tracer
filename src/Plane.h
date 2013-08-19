

#ifndef PLANE_H
#define PLANE_H

#include "I_GenericShape.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"

/*
***************************************************************
*
* Class that represents a plane that a ray can intersect with
* The plane will always intersect with the ray unless the ray is parallel 
* to the plane.  Mainly a base class for the Triangle shape.  
*
***************************************************************
*/
class Plane : public I_GenericShape
{
public:
   Plane(Point3D one, Point3D two, Point3D three);
   ~Plane();

   virtual Intersection intersects(Ray& ray);

protected:
   Point3D one_;
   Point3D two_;
   Point3D three_;
   Vector3D normal_;

   double d_;
};

#endif
