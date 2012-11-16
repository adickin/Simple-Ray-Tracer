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
   Point3D point(-90,30,0);
   shapes_.push_back(new Sphere(point, 20));

   point.setX(0);
   point.setY(0);
   point.setZ(0);
   shapes_.push_back(new Sphere(point, 20));

   cameraLocation_.setX(0);
   cameraLocation_.setY(0);
   cameraLocation_.setZ(150);

   cameraDirection_.setX(0);
   cameraDirection_.setY(0);
   cameraDirection_.setZ(-30);

   cameraUp_.setY(1);

   imageHeight_ = 480;
   imageWidth_ = 640;

   w_ = imageWidth_;
   h_ = imageHeight_;
   z_ = cameraLocation_.z();
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
         Point3D point(x - (imageWidth_/2), y - (imageHeight_/2), 0);

         Vector3D vector(cameraLocation_, point);
         vector.normalizeVector();

         Ray ray;
         ray.setDirectionVector(vector);
         ray.setStartPoint(cameraLocation_);

         for(int i = 0; i < shapes_.size(); i++)
         {
            bool hit = shapes_.at(i)->intersects(&ray);
            if(hit)
            {
               image_->setPixel(x, y, qRgb(255, 0, 0));
            }
         }
      }
   }
}

// void Scene::drawScene()
// {
//    Ray ray;
//    ray.setStartPoint(cameraLocation_);
//    for(int x = 0; x < imageWidth_; x++)
//    {
//       for(int y = 0; y < imageHeight_; y++)
//       {
//          //Point3D point(x - (imageWidth_/2), y - (imageHeight_/2), imagePlane_);
//          double dx = 400.0/imageWidth_;
//          double dy = 400.0/imageHeight_;

//          double tempX = -200.0 + (x) * dx;
//          double tempY = 200.0 - (y) * dy;
//          Point3D tempPoint(tempX, tempY, 0);

//          Vector3D vector(cameraLocation_, tempPoint);
//          vector.normalizeVector();
//          ray.setDirectionVector(vector);

//          for(int i = 0; i < shapes_.size(); i++)
//          {
//             bool hit = shapes_.at(i)->intersects(&ray);
//             if(hit)
//             {
//                image_->setPixel(x, y, qRgb(255, 0, 0));
//             }
//          }
//       }
//    }
// }
