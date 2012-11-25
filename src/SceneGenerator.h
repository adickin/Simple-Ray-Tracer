/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef SCENEGENERATOR_H
#define SCENEGENERATOR_H

#include <QList>
#include <QTextStream>

#include "Point3D.h"
#include "Colour.h"
class I_GenericShape;
class Light;

/*
***************************************************************
*
* Class that is used to read in a .scn file from disk.  Upon opening a file
* it reads in the file and stores the lights and objects in lists for retrival
* by other classes that need them.
*
***************************************************************
*/
class SceneGenerator
{
public:
   SceneGenerator();
   ~SceneGenerator();

   void loadSceneFromFile(QString& filename);

   QList<I_GenericShape*> getSceneObjects();
   QList<Light*> getSceneLights();

private:
   I_GenericShape* makeSphere(QTextStream& in);
   I_GenericShape* makeTriangle(QTextStream& in);
   I_GenericShape* makeQuad(QTextStream& in);
   Light* makeLight(QTextStream& in);

   Point3D makePoint(QString& pointString);
   double getRadius(QString& radiusString);
   QString getMaterial(QString& materialString);
   Colour getColour(QString& colourString);
   QList<I_GenericShape*> objects_;
   QList<Light*> lights_;

};

#endif
