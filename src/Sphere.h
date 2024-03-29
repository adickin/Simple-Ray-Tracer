

#ifndef SPHERE_H
#define SPHERE_H

#include "I_GenericShape.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"

class Sphere : public I_GenericShape
{
public:
   Sphere(Point3D& centerLocation, double radius);
   ~Sphere();

   virtual Intersection intersects(Ray& ray);

private:
   void fillIntersection(Intersection& intersection,
                        Ray& ray, double distance);
   double radius_;
   Point3D center_;
};

#endif
