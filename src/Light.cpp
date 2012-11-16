/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "Light.h"

Light::Light(Point3D location, Colour colour)
{
   location_ = location;
   lightColour_ = colour;
}

Light::~Light()
{

}