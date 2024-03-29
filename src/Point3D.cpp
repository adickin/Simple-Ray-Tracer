
#include "Point3D.h"
#include <QObject>

/*
***************************************************************
*
* Default constructor  
*
***************************************************************
*/
Point3D::Point3D()
{
   x_ = 0;
   y_ = 0;
   z_ = 0;
}

/*
***************************************************************
*
* overloaded constructor  
*
***************************************************************
*/
Point3D::Point3D(double x, double y, double z)
{
   x_ = x;
   y_ = y;
   z_ = z;
}

/*
***************************************************************
*
* Overloaded == operator to compare 2 points in space.  
*
***************************************************************
*/
bool Point3D::operator==(const Point3D &rhs)
{
   bool equal = true;
   equal &= qFuzzyCompare(1 + x_, 1 + rhs.x());
   equal &= qFuzzyCompare(1 + y_, 1 + rhs.y());
   equal &= qFuzzyCompare(1 + z_, 1 + rhs.z());
   return equal;
}

/*
***************************************************************
*
* Overloaded - operator to minus one point from another  
*
***************************************************************
*/
Point3D Point3D::operator-(const Point3D& rhs)
{
   return Point3D(x_ - rhs.x(), y_ - rhs.y(), z_ - rhs.z());
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
