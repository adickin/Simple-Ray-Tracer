

#include "Ray.h"

/*
***************************************************************
*
* Constructor for a generic ray.  
*
***************************************************************
*/
Ray::Ray()
{
   fromObjectId_ = -1;
   insideObject_ = false;
   refractionIndex_ = 1.0;
}

Ray::~Ray()
{

}

/*
***************************************************************
*
* Sets the point from where the ray starts from  
*
***************************************************************
*/
void Ray::setStartPoint(const Point3D& point)
{
   startPoint_.setX(point.x());
   startPoint_.setY(point.y());
   startPoint_.setZ(point.z());
}

/*
***************************************************************
*
* Sets the direction the ray is traveling.  
*
***************************************************************
*/
void Ray::setDirectionVector(const Vector3D& vector)
{
   direction_.setX(vector.x());
   direction_.setY(vector.y());
   direction_.setZ(vector.z());
}

/*
***************************************************************
*
* returns the start point for the ray  
*
***************************************************************
*/
Point3D Ray::startPoint()
{
   return startPoint_;
}

/*
***************************************************************
*
* returns the direction of the ray.  
*
***************************************************************
*/
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
