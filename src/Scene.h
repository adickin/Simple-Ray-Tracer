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
   Point3D cameraLocation_;

   int imageWidth_;
   int imageHeight_;
   int imagePlane_;

   QImage* image_;

};

#endif
