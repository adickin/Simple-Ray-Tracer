/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Point3D.h"

Point3D::Point3D()
{
   x_ = 0;
   y_ = 0;
   z_ = 0;
}

Point3D::Point3D(double x, double y, double z)
{
   x_ = x;
   y_ = y;
   z_ = z;
}

Point3D::~Point3D()
{

}

double Point3D::x() const
{
   return x_;
}

double Point3D::y() const
{
   return y_;
}

double Point3D::z() const
{
   return z_;
}

void Point3D::setX(double x)
{
   x_ = x;
}

void Point3D::setY(double y)
{
   y_ = y;
}

void Point3D::setZ(double z)
{
   z_ = z;
}
