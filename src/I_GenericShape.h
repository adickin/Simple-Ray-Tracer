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

#include <QString>

#include "Colour.h"
#include "Point3D.h"
#include "Ray.h"
#include "Vector3D.h"

struct Material
{
   Colour ambient;
   Colour diffuse;
   Colour specular;

   double localIllumination;
   double reflectedIllumination;

   double shinyness;
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

/*
***************************************************************
*
* Parent class of all shapes that shares functions that are common
* between all shapes.  Provides a virtual intersects function that must
* be implemented by children of this class  
*
***************************************************************
*/
class I_GenericShape
{

public:
   I_GenericShape();
   ~I_GenericShape();

   int shapeId();

   Material material();
   void setMaterial(QString& material);

   void setMaterialChrome();
   void setMaterialBronze();
   void setMaterialBlue();
   void setMaterialRed();
   void setMaterialOrange();
   void setMaterialYellow();
   void setMaterialGreen();
   void setMaterialIndigo();
   void setMaterialViolet();
   void setMaterialWhite();
   void setMaterialBlack();
   void setMaterialBrass();
   void setMaterialEmerald();
   void setMaterialJade();
   void setMaterialObsidian();
   void setMaterialPearl();
   void setMaterialRuby();
   void setMaterialTurquoise();
   void setMaterialRubber();
   void setMaterialGlass();

   //children must implement this function
   virtual Intersection intersects(Ray& ray) = 0;

protected:
   Material shapeMaterial_;
   int shapeId_;
};

#endif
