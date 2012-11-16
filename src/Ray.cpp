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

}

Ray::~Ray()
{

}

void Ray::setStartPoint(Point3D& point)
{
   startPoint_ = point;
}
void Ray::setDirectionVector(Vector3D& vector)
{
   direction_ = vector;
}

Point3D Ray::startPoint()
{
   return startPoint_;
}
Vector3D Ray::directionVector()
{
   return direction_;
}