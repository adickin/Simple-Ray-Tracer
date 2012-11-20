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
   shapes_.push_back(new Sphere(point, 50));
   //shapes_.at(0)->setMaterialChrome();

   point.setX(75);
   point.setY(0);
   point.setZ(0);
   shapes_.push_back(new Sphere(point, 50));
   shapes_.at(1)->setMaterialChrome();

   //  point.setX(0);
    point.setY(-100);
   //  point.setZ(0);
   //  shapes_.push_back(new Sphere(point, 50));
   // shapes_.at(2)->setMaterialChrome();

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
   Point3D lightLocation(150, 0, 0);
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

Colour Scene::trace(Ray& ray, int depth)
{
   if(depth == 5)
   {
      return Colour();
   }

   QList<Intersection> possibleIntersections;
   for(int i = 0; i < shapes_.size(); i++)
   {
      possibleIntersections << shapes_.at(i)->intersects(ray);
   }

   Intersection intersection = getClosestIntersection(possibleIntersections);

   if(intersection.valid == false ||
      ray.fromObjectId() == intersection.objectId)
   {
      return Colour();
   }

   Colour localColour = getPixelColour(intersection);

   Ray reflectionRay;
   Vector3D reflection = Vector3D::calculateReflectionVector(intersection.normal,
                                     intersection.rayFromCamera.directionVector());
   reflectionRay.setStartPoint(intersection.intersectionPointClosest);
   reflectionRay.setDirectionVector(reflection);
   reflectionRay.setFromObjectId(intersection.objectId);

   Colour reflectedColour = trace(reflectionRay, ++depth);
   reflectedColour.multiplyColourByConstant(0.5);
   return localColour + reflectedColour;
}

Colour Scene::getPixelColour(Intersection& intersection)
{
   //Initializes to black
   Colour pixelColour;
   if(intersection.valid)
   {
      bool inShadow = isPointInShadow(intersection);
      if(!inShadow)
      {
         //fprintf(stderr, "getting here\n");
         pixelColour = lightOne_->phongLighting(intersection);
      }
      else
      {
         pixelColour = lightOne_->diffuseLight(intersection);
      }
   }
   return pixelColour;
}

/*
***************************************************************
*
*   
*
***************************************************************
*/
Intersection Scene::getClosestIntersection(QList<Intersection>& intersections)
{
   int closestIntersectionIndex = 0;
   if(intersections.size()  > 1)
   {
      //two or more possible intersections with this ray, find the closest
      double smallestDistance = -1;
      for(int i = 0; i < intersections.size(); i++)
      {
         bool isIntersectionCloser = (smallestDistance > intersections.at(i).distanceFromCamera ||
                                    smallestDistance == -1) &&
                                    intersections.at(i).valid;
         if(isIntersectionCloser)
         {
            smallestDistance = intersections.at(i).distanceFromCamera;
            closestIntersectionIndex = i;
         }
      }
   }

   return intersections[closestIntersectionIndex];
}

bool Scene::isPointInShadow(Intersection& intersection)
{
   bool isInShadow = false;
   Ray ray;
   Vector3D shadowBeam(intersection.intersectionPointClosest, lightOne_->location());
   shadowBeam.normalizeVector();
   ray.setDirectionVector(shadowBeam);
   ray.setStartPoint(intersection.intersectionPointClosest);
   ray.setFromObjectId(intersection.objectId);

   Intersection currentPoint;
   for(int i = 0; i < shapes_.size(); i++)
   {
      currentPoint = shapes_.at(i)->intersects(ray);

      isInShadow = currentPoint.objectId != ray.fromObjectId() &&
                   currentPoint.valid;
      //isInShadow = currentPoint.valid;

      if(isInShadow)
      {
         break;
      }
   }

   return isInShadow;
}
