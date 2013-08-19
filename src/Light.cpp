
#include "Light.h"
#include "math.h"

/*
***************************************************************
*
* constructor that defines the lights location and colour.  
*
***************************************************************
*/
Light::Light(Point3D location, Colour colour)
{
   location_ = location;
   lightColour_ = colour;
}

Light::~Light()
{

}

/*
***************************************************************
*
*  function that returns the phong lighting colour at an intersection pont  
*
***************************************************************
*/
Colour Light::phongLighting(Intersection& intersection)
{
   return ambientLight(intersection) + diffuseLight(intersection) +
      specularLight(intersection);
}

/*
***************************************************************
*
*  function that returns the ambient lighting colour at an intersection pont  
*
***************************************************************
*/
Colour Light::ambientLight(Intersection& intersection)
{
   Colour ambientColour = lightColour_ * intersection.material.ambient;
   return ambientColour;
}

/*
***************************************************************
*
*  function that returns the diffuse lighting colour at an intersection pont  
*
***************************************************************
*/
Colour Light::diffuseLight(Intersection& intersection)
{
   Colour diffuseColour = lightColour_ * intersection.material.diffuse;
   Vector3D lightVector(intersection.intersectionPointClosest, location_);
   lightVector.normalizeVector();
   double nDotLight = intersection.normal.dotProduct(lightVector);
   if(nDotLight < 0)
   {
      nDotLight = 0;
   }
   diffuseColour.multiplyColourByConstant(nDotLight);

   return diffuseColour;
}

/*
***************************************************************
*
*  function that returns the specular lighting colour at an intersection pont  
*
***************************************************************
*/
Colour Light::specularLight(Intersection& intersection)
{
   Colour specularColour = lightColour_ * intersection.material.specular;

   Vector3D lightVector(intersection.intersectionPointClosest, location_);
   lightVector.normalizeVector();

   Vector3D reflection = Vector3D::calculateReflectionVector(intersection.normal, lightVector);

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

/*
***************************************************************
*
* returns the lights location.  
*
***************************************************************
*/
Point3D Light::location()
{
   return location_;
}
