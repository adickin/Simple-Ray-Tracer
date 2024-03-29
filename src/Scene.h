

#ifndef SCENE_H
#define SCENE_H

#include <QImage>
#include <QList>
#include <QThread>

#include "I_GenericShape.h"
#include "Light.h"
#include "Point3D.h"
#include "SceneGenerator.h"
#include "Vector3D.h"

class Ray;
class Colour;

/*
***************************************************************
*
* Represents the scene, holds the main recursive TRACE function that 
* is essential to a ray tracer.  Provides hookes into the scenegenerator
* that loads scenes from files.  Is threaded so that the GUI is still
* responsive while a scene is being traced.
*
***************************************************************
*/
class Scene : public QThread
{
   Q_OBJECT

public:
   Scene(QObject* parent = NULL);
   ~Scene();
   void run();

   void setImage(QImage* image);
   
public slots:
   void drawScene();
   void loadScene(QString& fileName);

signals:
   void finishedDrawing();
   void sceneLoadFinished();

private:
   Colour trace(Ray& ray, int depth);
   Colour getPixelColour(Intersection& intersection);
   Intersection getClosestIntersection(QList<Intersection>& intersections);
   bool isPointInShadow(Intersection& intersection, Light* light);

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
};

#endif
