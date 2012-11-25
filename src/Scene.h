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
#include "SceneGenerator.h"

class Ray;
class Colour;

#include "I_GenericShape.h"

class Scene : public QObject
{
   Q_OBJECT

public:
   Scene(QObject* parent = NULL);
   ~Scene();

   void setImage(QImage* image);
   void loadScene(QString& fileName);

public slots:
   void drawScene();

signals:
   void sceneLoaded();
   void finishedDrawing();
   

private:
   Colour trace(Ray& ray, int depth);
   Colour getPixelColour(Intersection& intersection);
   Intersection getClosestIntersection(QList<Intersection>& intersections);
   bool isPointInShadow(Intersection& intersection, Light* light);
//   Ray findRefractionRay(Ray& ray, Intersection& intersection);

private:
   QList<I_GenericShape*> shapes_;
   QList<Light*> lights_;
   SceneGenerator generator_;

   QImage* image_;

   //EYE
   Point3D cameraLocation_;

   //output image size.
   int imageWidth_;
   int imageHeight_;

   double indexAir_;

};

#endif
