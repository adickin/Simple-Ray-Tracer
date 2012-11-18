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
   Colour ambientColour = lightColour_ * intersection.material.ambient;


   //DIFFUSE
   Colour diffuseColour = lightColour_ * intersection.material.diffuse;
   Vector3D lightVector(location_, intersection.intersectionPointClosest);
   lightVector.normalizeVector();
   double nDotLight = intersection.normal.dotProduct(lightVector);
   if(nDotLight < 0)
   {
      nDotLight = 0;
   }
   diffuseColour.setRed(diffuseColour.red() * nDotLight);
   diffuseColour.setGreen(diffuseColour.green() * nDotLight);
   diffuseColour.setBlue(diffuseColour.blue() * nDotLight);

   //SPECULAR
   Colour specularColour = lightColour_ * intersection.material.specular;

   double nDotEyeVector = intersection.normal.dotProduct(intersection.rayFromCamera.directionVector());
   nDotEyeVector *= 2;

   Vector3D reflection;
   reflection.setX(intersection.normal.x() * nDotEyeVector);
   reflection.setY(intersection.normal.y() * nDotEyeVector);
   reflection.setZ(intersection.normal.z() * nDotEyeVector);
   reflection = reflection - intersection.rayFromCamera.directionVector();
   reflection.normalizeVector();

   double eyeVectorDotRefelction = intersection.rayFromCamera.directionVector().dotProduct(reflection);
   if(eyeVectorDotRefelction < 0)
   {
      eyeVectorDotRefelction = 0;//-1.0 * pow(fabs(eyeVectorDotRefelction), intersection.material.shinyness);
   }
   else
   {
      eyeVectorDotRefelction = pow(fabs(eyeVectorDotRefelction), intersection.material.shinyness);
   }

   specularColour.setRed(specularColour.red() * eyeVectorDotRefelction);
   specularColour.setGreen(specularColour.green() * eyeVectorDotRefelction);
   specularColour.setBlue(specularColour.blue() * eyeVectorDotRefelction);

   return ambientColour + diffuseColour + specularColour;
   return diffuseColour;
   //return specularColour;
}
