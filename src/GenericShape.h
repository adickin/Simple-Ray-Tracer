/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef GENERICSHAPE_H
#define GENERICSHAPE_H

#include <QObject>

class Point3D;
class Vector3D;

class GenericShape : public QObject
{
   Q_OBJECT

public:
   GenericShape( QObject* parent = NULL);
   ~GenericShape();

   virtual bool intersects(Point3D* point, Vector3D* vector) = 0;
};

#endif