/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/
#include "Vector3D.h"
#include "math.h"

/*
***************************************************************
*
* constructor  
*
***************************************************************
*/
Vector3D::Vector3D(double x, double y, double z)
:isUnitVector_(false)
,x_(x)
,y_(y)
,z_(z)
{

}

/*
***************************************************************
*
* Creates a vector from two coordinate points, Vertex one is always
* minused from vertex two.  
*
***************************************************************
*/
Vector3D::Vector3D(const Point3D& one, const Point3D& two)
:isUnitVector_(false)
{
   x_ = two.x() - one.x();
   y_ = two.y() - one.y();
   z_ = two.z() - one.z();
}

/*
***************************************************************
*
*  destructor 
*
***************************************************************
*/
Vector3D::~Vector3D()
{
   //does nothing
}

/*
***************************************************************
*
*  Performs a cross product with this vector and \a vector and loads
*  the result into this. 
*
***************************************************************
*/
void Vector3D::crossProduct(const Vector3D* vector)
{
   double tempX = ((y_ * vector->z_) - (z_ * vector->y_));
   double tempY = ((z_ * vector->x_) - (x_ * vector->z_));
   double tempZ = ((x_ * vector->y_) - (y_ * vector->x_));

   x_ = tempX;
   y_ = tempY;
   z_ = tempZ;
}

/*
***************************************************************
*
*  Normalizes a vector so that its magnitude is 1.  
*
***************************************************************
*/
void Vector3D::normalizeVector()
{
   double magnitude = sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));

   x_ = x_/magnitude;
   y_ = y_/magnitude;
   z_ = z_/magnitude;
   isUnitVector_ = true;
}

double Vector3D::x() const
{
   return x_;
}

double Vector3D::y() const
{
   return y_;
}

double Vector3D::z() const
{
   return z_;
}

void Vector3D::setX(double x)
{
   x_ = x;
}

void Vector3D::setY(double y)
{
   y_ = y;
}

void Vector3D::setZ(double z)
{
   z_ = z;
}
