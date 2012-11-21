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

Vector3D::Vector3D()
{
   x_ = 0;
   y_ = 0;
   z_ = 0;
}

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

Vector3D Vector3D::operator-(const Vector3D &rhs)
{
   Vector3D returnedVector;
   returnedVector.setX(x_ - rhs.x());
   returnedVector.setY(y_ - rhs.y());
   returnedVector.setZ(z_ - rhs.z());
   return returnedVector;
}

Vector3D& Vector3D::operator=(const Vector3D &rhs)
{
   x_ = rhs.x();
   y_ = rhs.y();
   z_ = rhs.z();

   return *this;
}

double Vector3D::dotProduct(const Vector3D& vector)
{
   double product = (x_ * vector.x()) + (y_ * vector.y()) + (z_ * vector.z());
   return product;
}

/*
***************************************************************
*
*  Performs a cross product with this vector and \a vector and loads
*  the result into this. 
*
***************************************************************
*/
Vector3D Vector3D::crossProduct(const Vector3D& vector)
{
   double tempX = ((y_ * vector.z_) - (z_ * vector.y_));
   double tempY = ((z_ * vector.x_) - (x_ * vector.z_));
   double tempZ = ((x_ * vector.y_) - (y_ * vector.x_));

   return Vector3D(tempX, tempY, tempZ);
}

double Vector3D::magnitude()
{
   double magnitude = sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));
   return magnitude;
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
   double magnitudeOfVector = magnitude();

   x_ = x_/magnitudeOfVector;
   y_ = y_/magnitudeOfVector;
   z_ = z_/magnitudeOfVector;
   isUnitVector_ = true;
}

void Vector3D::multiplyByConstant(double constant)
{
   setX(x_ * constant);
   setY(y_ * constant);
   setZ(z_ * constant);
}

Vector3D Vector3D::calculateReflectionVector(const Vector3D& normalVector, const Vector3D& incomingVector)
{
   Vector3D reflection = incomingVector;
   double nDotIncomingVector = reflection.dotProduct(normalVector);
   nDotIncomingVector *= 2;
   Vector3D tempVector = normalVector;
   tempVector.multiplyByConstant(nDotIncomingVector);
   reflection = reflection - tempVector;
   reflection.normalizeVector();

   return reflection;
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
