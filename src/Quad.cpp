

#include "Quad.h"

/*
***************************************************************
*
* Constructor for a quad to show up on the plane, The following rules must
* always be followed during construction of a quad.
*
* one must always be the top left of the quad
* two must always be the top right of the quad
* three must always be the bottom right of the quad
* four must always be the bottom left  
*
***************************************************************
*/
Quad::Quad(Point3D one, Point3D two, Point3D three, Point3D four)
   :I_GenericShape()
   ,triangleOne_(one, three, two)
   ,triangleTwo_(one, four, three)
{
   
}

Quad::~Quad()
{

}

/*
***************************************************************
*
* returns a Intersection if the ray intersects with the quad.  
*
***************************************************************
*/
Intersection Quad::intersects(Ray& ray)
{
   Intersection intersection = triangleOne_.intersects(ray);

   if(!intersection.valid)
   {
      intersection = triangleTwo_.intersects(ray);
   }
   intersection.material = shapeMaterial_;

   return intersection;
}
