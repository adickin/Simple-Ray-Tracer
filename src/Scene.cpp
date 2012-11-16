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

Scene::Scene()
{
   Point3D point(0,0,0);
   shapes_.push_back(new Sphere(point, 5));

   cameraLocation_.setX(0);
   cameraLocation_.setY(0);
   cameraLocation_.setZ(30);

   imageHeight_ = 480;
   imageWidth_ = 640;
   imagePlane_ = -100;
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
   for(int x = 0; x < imageWidth_; x++)
   {
      for(int y = 0; y < imageHeight_; y++)
      {
         Point3D point(x - (imageWidth_/2), y - (imageHeight_/2), imagePlane_);
         Vector3D vector(cameraLocation_, point);
         vector.normalizeVector();

         for(int i = 0; i < shapes_.size(); i++)
         {
            bool hit = shapes_.at(i)->intersects(&cameraLocation_, &vector);
            if(hit)
            {
               image_->setPixel(x, y, qRgb(255, 0, 0));
            }
         }
      }
   }
}
