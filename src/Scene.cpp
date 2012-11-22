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
#include "Plane.h"
#include "Triangle.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Light.h"
#include <QCoreApplication>

Scene::Scene(QObject* parent)
:QObject(parent)
{
   Point3D point(-50, 75, 0);
   shapes_.push_back(new Sphere(point, 50));
   shapes_.at(0)->setMaterialChrome();

   Point3D point2(50, 75, 0);
   shapes_.push_back(new Sphere(point2, 50));
   shapes_.at(1)->setMaterialChrome();

   Point3D point3(0, 50, 0);
   shapes_.push_back(new Sphere(point3, 25));
   shapes_.at(2)->setMaterialChrome();

   Point3D point4(0, 25, 0);
   shapes_.push_back(new Sphere(point4, 25));
   shapes_.at(3)->setMaterialChrome();

   Point3D point5(0, 0, 0);
   shapes_.push_back(new Sphere(point5, 25));
   shapes_.at(4)->setMaterialChrome();

   Point3D point6(0, -25, 0);
   shapes_.push_back(new Sphere(point6, 25));
   shapes_.at(5)->setMaterialChrome();

   Point3D point7(0, -50, 0);
   shapes_.push_back(new Sphere(point7, 25));
   shapes_.at(6)->setMaterialChrome();

   Point3D point8(0, -75, 0);
   shapes_.push_back(new Sphere(point8, 25));
   shapes_.at(7)->setMaterialChrome();

   Point3D point9(0, -100, 0);
   shapes_.push_back(new Sphere(point9, 25));
   shapes_.at(8)->setMaterialChrome();

   Point3D point10(0, -125, 0);
   shapes_.push_back(new Sphere(point10, 25));
   shapes_.at(9)->setMaterialChrome();

   // point.setX(0);
   // point.setY(-100);
   // point.setZ(0);
   // shapes_.push_back(new Sphere(point, 50));
   // shapes_.at(2)->setMaterialChrome();

    // point.setX(0);
    // point.setY(-300);
    // point.setZ(0);
    // shapes_.push_back(new Triangle());
    //shapes_.at(2)->setMaterialBlue();

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
   Point3D lightLocation(65, 75, 150);
   Light* lightOne;
   lightOne = new Light(lightLocation, Colour(0.0, 1.0, 0.0));
   lights_ << lightOne;

   Point3D lightLocation2(-65, 75, 150);
   Light* lightTwo;
   lightTwo = new Light(lightLocation2, Colour(1.0, 0.0, 0.0));
   lights_ << lightTwo;  

   Point3D lightLocation3(0, -75, 150);
   Light* lightThree;
   lightThree = new Light(lightLocation3, Colour(0.0, 0.0, 1.0));
   lights_ << lightThree;  
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
         emit imageChanged();
         QCoreApplication::processEvents();
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

   if(intersection.valid == false)
   {
      return Colour();
   }

   Colour localColour = getPixelColour(intersection);
   localColour.multiplyColourByConstant(intersection.material.localIllumination);

   Ray reflectionRay;
   Vector3D reflection = Vector3D::calculateReflectionVector(intersection.normal,
                                     ray.directionVector());
   reflectionRay.setStartPoint(intersection.intersectionPointClosest);
   reflectionRay.setDirectionVector(reflection);
   reflectionRay.setFromObjectId(intersection.objectId);

   Colour reflectedColour = trace(reflectionRay, ++depth);
   reflectedColour.multiplyColourByConstant(intersection.material.reflectedIllumination);
   return localColour + reflectedColour;
}

Colour Scene::getPixelColour(Intersection& intersection)
{
   Colour pixelColour = intersection.material.ambient;
   foreach(Light* currentLight, lights_)
   {
      //Initializes to black
      if(intersection.valid)
      {
         bool inShadow = isPointInShadow(intersection, currentLight);
         if(!inShadow)
         {
            pixelColour = pixelColour + currentLight->diffuseLight(intersection);
            pixelColour = pixelColour + currentLight->specularLight(intersection);
         }
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
   Intersection tempIntersection;
   tempIntersection.valid = false;
   tempIntersection.distanceFromCamera = 0.0;

   foreach(Intersection intersection, intersections)
   {
      if(intersection.valid)
      {
         if(!tempIntersection.valid)
         {
            tempIntersection = intersection;
         }
         else if(intersection.distanceFromCamera < tempIntersection.distanceFromCamera)
         {
            tempIntersection = intersection;
         }
      }
   }
   return tempIntersection;
}

bool Scene::isPointInShadow(Intersection& intersection, Light* light)
{
   //return false;
   bool isInShadow = false;
   Ray ray;
   Vector3D shadowBeam(intersection.intersectionPointClosest, light->location());
   double lightDistance = shadowBeam.magnitude();
   shadowBeam.normalizeVector();
   ray.setDirectionVector(shadowBeam);
   ray.setStartPoint(intersection.intersectionPointClosest);
   ray.setFromObjectId(intersection.objectId);

   Intersection currentPoint;
   for(int i = 0; i < shapes_.size(); i++)
   {
      currentPoint = shapes_.at(i)->intersects(ray);

      isInShadow = currentPoint.valid && currentPoint.distanceFromCamera < lightDistance &&
      currentPoint.distanceFromCamera > 0;

      if(isInShadow)
      {
         break;
      }
   }

   return isInShadow;
}
