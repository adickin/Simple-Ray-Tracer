/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QImage>
#include "Point3D.h"
#include "Vector3D.h"

class I_GenericShape;

class Scene
{

public:
   Scene();
   ~Scene();

   void drawScene();
   void setImage(QImage* image);

private:
   QList<I_GenericShape*> shapes_;

   //EYE
   Point3D cameraLocation_;
   Vector3D cameraDirection_;
   Vector3D cameraUp_;

   //output image size.
   int imageWidth_;
   int imageHeight_;

   //image plane
   double w_;
   double h_;
   double z_;

   QImage* image_;

};

#endif
