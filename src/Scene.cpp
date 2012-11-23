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
:QObject(parent)
{
   indexAir_ = 1.000029;

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
   Point3D lightLocation(0, 0, 100);
   Light* lightOne;
   lightOne = new Light(lightLocation, Colour(1.0, 1.0, 1.0));
   lights_ << lightOne;

   // Point3D lightLocation2(-65, 0, 150);
   // Light* lightTwo;
   // lightTwo = new Light(lightLocation2, Colour(1.0, 0.7, 0.0));
   // lights_ << lightTwo;  

   // Point3D lightLocation3(-65, -75, 150);
   // Light* lightThree;
   // lightThree = new Light(lightLocation3, Colour(1.0, 1.0, 1.0));
   // lights_ << lightThree;  
}

Scene::~Scene()
{

}

void Scene::setImage(QImage* image)
{
   image_ = image;
}

void Scene::loadScene(QString& fileName)
{
   fprintf(stderr, "loading\n");
   generator_.loadSceneFromFile(fileName);
   fprintf(stderr, "finsihed loading\n");
   shapes_.append(generator_.getSceneObjects());
   fprintf(stderr, "shapes amount %d\n", shapes_.size());
   drawScene();

   emit finishedDrawing();
}

void Scene::drawScene()
{
   fprintf(stderr, "starting\n");
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
         ray.setRefractionIndex(indexAir_);

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

// /*
// ***************************************************************
// *
// *   
// *
// ***************************************************************
// */
// Ray Scene::findRefractionRay(Ray& ray, Intersection& intersection)
// {
//    double mediumOne;
//    double mediumTwo;
//    Vector3D refractedVector;
//    if(ray.insideObject())
//    {
//       mediumOne = intersection.material.refractionIndex;
//       mediumTwo = indexAir_;
//    }
//    else
//    {
//       mediumOne = indexAir_;
//       mediumTwo = intersection.material.refractionIndex;
//    }


//    double n = mediumTwo/mediumOne;

//    double cosI = intersection.normal.dotProduct(ray.directionVector());
//    double sinT2 = n*n * (1.0 - cosI*cosI);

//    bool valid = true;
//    if(sinT2 > 1.0)
//    {
//       valid = false;
//       fprintf(stderr, "TIR\n");
//    }
//    else
//    {
//       fprintf(stderr, "YAY\n");
//       refractedVector = intersection.normal;
//       Vector3D temp = ray.directionVector();
//       temp.multiplyByConstant(n);
//       refractedVector.multiplyByConstant(n + sqrt(1.0 - sinT2));
//       refractedVector = temp - refractedVector;
//    }

//    Ray refractedRay;
//    refractedRay.valid = valid;
//    refractedRay.setDirectionVector(refractedVector);
//    refractedRay.setStartPoint(intersection.intersectionPointClosest);
//    refractedRay.setInsideObject(false);

//    // double nDotL = intersection.normal.dotProduct(ray.directionVector());
//    // double signNDotL = sin(nDotL);
//    // double sqrtStuffMinusDotN = sqrt((1-n*n) + (nDotL*nDotL)*(n*n)) - nDotL*n;

//    // Vector3D temp = intersection.normal;
//    // temp.multiplyByConstant(signNDotL * sqrtStuffMinusDotN);

//    // Vector3D temp2 = ray.directionVector();
//    // temp2.multiplyByConstant(n);

//    // refractedVector = temp + temp2;
//    // refractedVector.normalizeVector();

//    // Ray refractedRay;
//    // refractedRay.setDirectionVector(refractedVector);
//    // refractedRay.setStartPoint(intersection.intersectionPointClosest);
//    // refractedRay.setFromObjectId(intersection.objectId);
//    // if(ray.insideObject())
//    // {
//    //    refractedRay.setInsideObject(false);
//    // }
//    // else
//    // {
//    //    refractedRay.setInsideObject(true);
//    // }

//    return refractedRay;
// }
