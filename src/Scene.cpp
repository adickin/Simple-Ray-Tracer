/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Scene.h"
#include "Sphere.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Light.h"

Scene::Scene()
{
   Point3D point(-75,0, 0);
   shapes_.push_back(new Sphere(point, 100));
   //shapes_.at(0)->setMaterialChrome();

   point.setX(75);
   point.setY(0);
   point.setZ(0);
   shapes_.push_back(new Sphere(point, 25));
   //shapes_.at(1)->setMaterialChrome();

   // point.setX(0);
   // point.setY(-100);
   // point.setZ(0);
   // shapes_.push_back(new Sphere(point, 50));
   //shapes_.at(1)->setMaterialChrome();

   cameraLocation_.setX(0);
   cameraLocation_.setY(0);
   cameraLocation_.setZ(720);

   cameraDirection_.setX(0);
   cameraDirection_.setY(0);
   cameraDirection_.setZ(-30);

   cameraUp_.setY(1);

   imageHeight_ = 480;
   imageWidth_ = 640;

   w_ = imageWidth_;
   h_ = imageHeight_;
   z_ = cameraLocation_.z();

   //Make a Light
   Point3D lightLocation(75, 0, 100);
   lightOne_ = new Light(lightLocation, Colour(1.0, 1.0, 1.0));
  
}

Scene::~Scene()
{

}

void Scene::setImage(QImage* image)
{
   image_ = image;
}

void Scene::drawScene()
{
   Ray ray;
   for(int x = 0; x < imageWidth_; x++)
   {
      for(int y = 0; y < imageHeight_; y++)
      {
         Point3D point(x - (imageWidth_/2), -y + (imageHeight_/2), -200);

         Vector3D vector(cameraLocation_, point);
         vector.normalizeVector();
         
         ray.setDirectionVector(vector);
         ray.setStartPoint(cameraLocation_);

         Colour colour = trace(ray, 0);

         image_->setPixel(x, y, qRgb(colour.red()*255, colour.green()*255, colour.blue()*255));
      }
   }
}

Colour Scene::trace(Ray& ray, int temp)
{
   //fprintf(stderr, "Depth %d\n", temp);
   if(temp == 5)
   {
      return Colour();
   }
   QList<Intersection> possibleIntersections;

   for(int i = 0; i < shapes_.size(); i++)
   {
      possibleIntersections << shapes_.at(i)->intersects(ray);
   }

   int closestIntersectionIndex = 0;
   if(possibleIntersections.size()  > 1)
   {
      //two or more possible intersections with this ray, find the closest
      double smallestDistance = -1;
      for(int i = 0; i < possibleIntersections.size(); i++)
      {
         bool isIntersectionCloser = (smallestDistance > possibleIntersections.at(i).distanceFromCamera ||
                                    smallestDistance == -1) &&
                                    possibleIntersections.at(i).valid;
         if(isIntersectionCloser)
         {
            smallestDistance = possibleIntersections.at(i).distanceFromCamera;
            closestIntersectionIndex = i;
         }
      }
   }


   if(possibleIntersections.at(closestIntersectionIndex).valid == false ||
      ray.fromObjectId() == possibleIntersections.at(closestIntersectionIndex).objectId)
   {
      return Colour();
   }

   Intersection intersection = possibleIntersections.at(closestIntersectionIndex);

   Colour colour = getPixelColour(possibleIntersections.at(closestIntersectionIndex));

   Ray reflectionRay;
   //*************************************************************************
   // //Make reflection vector
   // //Vector3D lightVector(lightOne_->location(), intersection.intersectionPointClosest);

   // //double nDotEyeVector = intersection.normal.dotProduct(intersection.rayFromCamera.directionVector());
   // double nDotEyeVector = intersection.normal.dotProduct(lightVector);
   // nDotEyeVector *= 2;

   // Vector3D reflection = intersection.normal;
   // reflection.multiplyByConstant(nDotEyeVector);
   // //reflection = reflection - intersection.rayFromCamera.directionVector();
   // reflection = reflection - lightVector;
   // reflection.normalizeVector();

   Vector3D reflection = intersection.rayFromCamera.directionVector();
   reflection.multiplyByConstant(-1);

   double nDotEyeVector = reflection.dotProduct(intersection.normal);
   nDotEyeVector *= 2;
   Vector3D multiplied = intersection.normal;
   multiplied.multiplyByConstant(nDotEyeVector);

   reflection = reflection - multiplied;
   //****************************************************************************
   reflectionRay.setStartPoint(possibleIntersections.at(closestIntersectionIndex).intersectionPointClosest);
   reflectionRay.setDirectionVector(reflection);

   //fprintf(stderr, "%d\n", intersection.objectId);
   reflectionRay.setFromObjectId(intersection.objectId);
   //fprintf(stderr, "adfalskdjfhlak  %d\n", reflectionRay.fromObjectId());
   Colour reflectedColour = trace(reflectionRay, ++temp);

   //return reflectedColour;
   return colour + reflectedColour;
}

Colour Scene::getPixelColour(Intersection intersection)
{
   //Initializes to black
   Colour pixelColour;
   if(intersection.valid)
   {
      pixelColour = lightOne_->phongLighting(intersection);


      // Intersection objectIntersectionBeforeHittingLight;
      // Ray ray;
      //    //Vector3D shadowBeam(intersection.intersectionPointClosest, lightOne_->location());
      // Vector3D shadowBeam(lightOne_->location(), intersection.intersectionPointClosest);
      // shadowBeam.normalizeVector();
      // ray.setDirectionVector(shadowBeam);
      // ray.setStartPoint(intersection.intersectionPointClosest);
      // ray.setFromObjectId(intersection.objectId);

      // for(int i = 0; i < shapes_.size(); i++)
      // {

      //    objectIntersectionBeforeHittingLight = shapes_.at(i)->intersects(ray);

      //    if(objectIntersectionBeforeHittingLight.valid &&
      //       objectIntersectionBeforeHittingLight.objectId != ray.fromObjectId() )
      //    {
      //       fprintf(stderr, "in shadow\n");
      //       pixelColour = Colour();
      //    }
      //    else
      //    {
      //       fprintf(stderr, "not in shadow\n");
      //    }
      // }

   }
   return pixelColour;
}

/*
***************************************************************
*
*  Make initial ray somewhere and have a function called trace that is recursive.
   Trace should return a colour and what not. and the returned colour is the pixel colour  
   -May want to find all the intersections before determiing a colour sine you only want to draw the closest intersection
*
***************************************************************
*/