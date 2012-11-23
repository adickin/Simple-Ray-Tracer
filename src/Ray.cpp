/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Ray.h"

Ray::Ray()
{
   fromObjectId_ = -1;
   insideObject_ = false;
   refractionIndex_ = 1.0;
}

Ray::~Ray()
{

}

void Ray::setStartPoint(const Point3D& point)
{
   startPoint_.setX(point.x());
   startPoint_.setY(point.y());
   startPoint_.setZ(point.z());
}
void Ray::setDirectionVector(const Vector3D& vector)
{
   direction_.setX(vector.x());
   direction_.setY(vector.y());
   direction_.setZ(vector.z());
}

Point3D Ray::startPoint()
{
   return startPoint_;
}

Vector3D Ray::directionVector()
{
   return direction_;
}

void Ray::setFromObjectId(int objectId)
{
   fromObjectId_ = objectId;
}

int Ray::fromObjectId()
{
   return fromObjectId_;
}

void Ray::setInsideObject(bool inside)
{
   insideObject_ = inside;
}

void Ray::setRefractionIndex(double refractionIndex)
{
   refractionIndex_ = refractionIndex;
}

bool Ray::insideObject()
{
   return insideObject_;
}

double Ray::refractionIndex()
{
   return refractionIndex_;
}
