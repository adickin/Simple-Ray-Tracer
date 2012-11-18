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
   Point3D point(0,0,0);
   shapes_.push_back(new Sphere(point, 100));

   //point.setX(0);
   //point.setY(0);
   //point.setZ(-50);
   //Colour colour(0.6, 0.1, 0.9);
   //shapes_.push_back(new Sphere(point, 20));

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
   Point3D lightLocation(100, 0, 200);
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

         Colour colour = trace(ray);

         image_->setPixel(x, y, qRgb(colour.red()*255, colour.green()*255, colour.blue()*255));
      }
   }
}

Colour Scene::trace(Ray& ray)
{
   Intersection intersection;
   for(int i = 0; i < shapes_.size(); i++)
   {
      intersection = shapes_.at(i)->intersects(ray);
   }
   Colour colour = getPixelColour(intersection);
   return colour;
}

Colour Scene::getPixelColour(Intersection intersection)
{
   //Initializes to black
   Colour pixelColour;
   if(intersection.valid)
   {

      pixelColour = lightOne_->phongLighting(intersection);
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