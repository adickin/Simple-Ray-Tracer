/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Light.h"
#include "math.h"

Light::Light(Point3D location, Colour colour)
{
   location_ = location;
   lightColour_ = colour;
}

Light::~Light()
{

}

Colour Light::phongLighting(Intersection& intersection)
{
   return ambientLight(intersection) + diffuseLight(intersection) +
      specularLight(intersection);
}

Colour Light::ambientLight(Intersection& intersection)
{
   Colour ambientColour = lightColour_ * intersection.material.ambient;
   return ambientColour;
}

Colour Light::diffuseLight(Intersection& intersection)
{
   Colour diffuseColour = lightColour_ * intersection.material.diffuse;
   Vector3D lightVector(location_, intersection.intersectionPointClosest);
   lightVector.normalizeVector();
   double nDotLight = intersection.normal.dotProduct(lightVector);
   if(nDotLight < 0)
   {
      nDotLight = 0;
   }
   diffuseColour.multiplyColourByConstant(nDotLight);

   return diffuseColour;
}

Colour Light::specularLight(Intersection& intersection)
{
   Colour specularColour = lightColour_ * intersection.material.specular;

   Vector3D lightVector(location_, intersection.intersectionPointClosest);

   double nDotEyeVector = intersection.normal.dotProduct(lightVector);
   nDotEyeVector *= 2;

   Vector3D reflection = intersection.normal;
   reflection.multiplyByConstant(nDotEyeVector);
   reflection = reflection - lightVector;
   reflection.normalizeVector();

   double eyeVectorDotRefelction = intersection.rayFromCamera.directionVector().dotProduct(reflection);
   if(eyeVectorDotRefelction < 0)
   {
      eyeVectorDotRefelction = 0;
   }
   else
   {
      eyeVectorDotRefelction = pow(eyeVectorDotRefelction, intersection.material.shinyness);
   }
   specularColour.multiplyColourByConstant(eyeVectorDotRefelction);

   return specularColour;
}

Point3D Light::location()
{
   return location_;
}
