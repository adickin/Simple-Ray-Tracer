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
#include <QObject>
#include "Point3D.h"
#include "Vector3D.h"
#include "Light.h"

class Ray;
class Colour;

#include "I_GenericShape.h"

class Scene : public QObject
{
   Q_OBJECT

public:
   Scene(QObject* parent = NULL);
   ~Scene();

   void drawScene();
   Colour trace(Ray& ray, int depth);
   void setImage(QImage* image);

signals:
   void imageChanged();
   

private:
   Colour getPixelColour(Intersection& intersection);
   Intersection getClosestIntersection(QList<Intersection>& intersections);
   bool isPointInShadow(Intersection& intersection, Light* light);

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

   //Light
   QList<Light*> lights_;
   //Light* lightOne_;

};

#endif
