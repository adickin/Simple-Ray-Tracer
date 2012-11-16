/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3D.h"
#include "Point3D.h"
class Light
{
public:
   Light();
   ~Light();

private:
   Vector3D direction_;
   Point3D startPoint_;
};

#endif