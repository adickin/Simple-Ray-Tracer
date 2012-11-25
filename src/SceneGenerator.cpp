/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 
*********************************************************************
*/

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "SceneGenerator.h"

#include "Quad.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Light.h"

static const QString TRIANGLE = "Triangle";
static const QString QUAD = "Quad";
static const QString SPHERE = "Sphere";
static const QString LIGHT = "Light";

SceneGenerator::SceneGenerator()
{

}

SceneGenerator::~SceneGenerator()
{
   objects_.clear();
   lights_.clear();
}

void SceneGenerator::loadSceneFromFile(QString& filename)
{
   objects_.clear();
   lights_.clear();
   QFile file(filename);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

   QTextStream in(&file);
   while (!in.atEnd()) 
   {
      QString line = in.readLine();
      if(line.contains(SPHERE) && !line.contains(QString("!")))
      {
         objects_ << makeSphere(in);
      }
      else if(line.contains(QUAD) && !line.contains(QString("!")))
      {
         objects_ << makeQuad(in);
      }
      else if(line.contains(TRIANGLE) && !line.contains(QString("!")))
      {
         objects_ << makeTriangle(in);
      }
      else if(line.contains(LIGHT) && !line.contains(QString("!")))
      {
         lights_ << makeLight(in);
      }
   }
}

I_GenericShape* SceneGenerator::makeSphere(QTextStream& in)
{
   QString pointOneString = in.readLine();
   QString radiusString = in.readLine();
   QString materialString = in.readLine();
   Point3D point = makePoint(pointOneString);
   double radius = getRadius(radiusString);
   QString material = getMaterial(materialString);
   Sphere* sphere = new Sphere(point, radius);
   sphere->setMaterial(material);
   return sphere;
}

I_GenericShape* SceneGenerator::makeTriangle(QTextStream& in)
{
   QString pointOneString = in.readLine();
   QString pointTwoString = in.readLine();
   QString pointThreeString = in.readLine();
   QString materialString = in.readLine();
   Point3D point = makePoint(pointOneString);
   Point3D point2 = makePoint(pointTwoString);
   Point3D point3 = makePoint(pointThreeString);
   materialString = getMaterial(materialString);

   Triangle* triangle = new Triangle(point, point2, point3);
   triangle->setMaterial(materialString);
   return triangle;
}

I_GenericShape* SceneGenerator::makeQuad(QTextStream& in)
{
   QString pointOneString = in.readLine();
   QString pointTwoString = in.readLine();
   QString pointThreeString = in.readLine();
   QString pointFourString = in.readLine();
   QString materialString = in.readLine();
   Point3D point = makePoint(pointOneString);
   Point3D point2 = makePoint(pointTwoString);
   Point3D point3 = makePoint(pointThreeString);
   Point3D point4 = makePoint(pointFourString);
   materialString = getMaterial(materialString);

   Quad* quad = new Quad(point, point2, point3, point4);
   quad->setMaterial(materialString);
   return quad;
}

Light* SceneGenerator::makeLight(QTextStream& in)
{
   QString pointOneString = in.readLine();
   QString colourString = in.readLine();

   Point3D point = makePoint(pointOneString);
   Colour colour = getColour(colourString);

   Light* light = new Light(point, colour);

   return light;
}

Point3D SceneGenerator::makePoint(QString& pointString)
{
   pointString.replace(QString("Point("), QString(""), Qt::CaseInsensitive);
   pointString.replace(QString(")"), QString(""), Qt::CaseInsensitive);

   QStringList points = pointString.split(QString(","));

   if(points.size() == 3)
   {
      double x = points.at(0).toDouble();
      double y = points.at(1).toDouble();
      double z = points.at(2).toDouble();
      return Point3D(x, y, z);
   }
   return Point3D();
}

double SceneGenerator::getRadius(QString& radiusString)
{
   radiusString.replace(QString("Radius("), QString(""), Qt::CaseInsensitive);
   radiusString.replace(QString(")"), QString(""), Qt::CaseInsensitive);

   return radiusString.toDouble();
}

QString SceneGenerator::getMaterial(QString& materialString)
{
   materialString.replace(QString("Material("), QString(""), Qt::CaseInsensitive);
   materialString.replace(QString(")"), QString(""), Qt::CaseInsensitive);
   materialString = materialString.trimmed();
   return materialString;
}

Colour SceneGenerator::getColour(QString& colourString)
{  
   colourString.replace(QString("Colour("), QString(""), Qt::CaseInsensitive);
   colourString.replace(QString(")"), QString(""), Qt::CaseInsensitive);

   QStringList points = colourString.split(QString(","));

   if(points.size() == 3)
   {
      double x = points.at(0).toDouble();
      double y = points.at(1).toDouble();
      double z = points.at(2).toDouble();
      return Colour(x, y, z);
   }
   return Colour();
}

QList<I_GenericShape*> SceneGenerator::getSceneObjects()
{
   return objects_;
}

QList<Light*> SceneGenerator::getSceneLights()
{
   return lights_;
}