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
#include "Quad.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Light.h"
#include <QCoreApplication>
#include "math.h"

Scene::Scene(QObject* parent)
:QThread(parent)
{
   cameraLocation_.setX(0);
   cameraLocation_.setY(0);
   cameraLocation_.setZ(850);

   imageHeight_ = 480;
   imageWidth_ = 640;
}

Scene::~Scene()
{

}

void Scene::run()
{
   drawScene();
}

void Scene::setImage(QImage* image)
{
   image_ = image;
}

void Scene::loadScene(QString& fileName)
{
   shapes_.clear();
   lights_.clear();
   generator_.loadSceneFromFile(fileName);
   shapes_.append(generator_.getSceneObjects());
   lights_.append(generator_.getSceneLights());
   emit sceneLoadFinished();
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
   emit finishedDrawing();
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

   Colour reflectedColour = trace(reflectionRay, depth+1);
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
