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
#include "Plane.h"
#include "Point3D.h"
#include "Quad.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Vector3D.h"
#include <QCoreApplication>

/*
***************************************************************
*
*   constructor 
*
***************************************************************
*/
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

/*
***************************************************************
*
* function ran when the thread is started.  
*
***************************************************************
*/
void Scene::run()
{
   drawScene();
}

/*
***************************************************************
*
* sets the image that will be modifyed while ray tracing.  
*
***************************************************************
*/
void Scene::setImage(QImage* image)
{
   image_ = image;
}

/*
***************************************************************
*
*  function that uses the scene generator to get a scene from a file. 
*
***************************************************************
*/
void Scene::loadScene(QString& fileName)
{
   shapes_.clear();
   lights_.clear();
   generator_.loadSceneFromFile(fileName);
   shapes_.append(generator_.getSceneObjects());
   lights_.append(generator_.getSceneLights());
   emit sceneLoadFinished();
}

/*
***************************************************************
*
* starts the main ray tracing sequence, creates rays from the camera to the location
* on the image and then calls trace on that ray.  
*
***************************************************************
*/
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

/*
***************************************************************
*
* recursive trace function that traces a ray to a max depth of 5.  
*
***************************************************************
*/
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

/*
***************************************************************
*
* get the pixel colour for an intersection if it is valid.  
*
***************************************************************
*/
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
* Multiple intersections can happen when a ray is fired,  this function
* returns the closest valid intersection from a list of intersections
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

/*
***************************************************************
*
* returns if the point is in line of site of at least 1 light.  
*
***************************************************************
*/
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
