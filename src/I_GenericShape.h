/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef I_GENERICSHAPE_H
#define I_GENERICSHAPE_H

#include "Colour.h"

#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"


struct Material
{
   Colour ambient;
   Colour diffuse;
   Colour specular;

   double localIllumination;
   double reflectedIllumination;
   double shinyness;
   Colour emission;
};

struct Intersection
{
   bool valid;
   Ray rayFromCamera;
   Vector3D normal;
   double distanceFromCamera;
   int objectId;

   Point3D intersectionPointClosest;

   Material material;
   double attenuation;
};


class I_GenericShape
{

public:
   I_GenericShape();
   ~I_GenericShape();

   int shapeId();

   Material material();
   void setMaterial(Material& colour);

   void setMaterialChrome();
   void setMaterialBronze();
   void setMaterialBlue();

   virtual Intersection intersects(Ray& ray) = 0;

protected:
   Material shapeMaterial_;
   int shapeId_;
};

#endif
