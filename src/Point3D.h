/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef POINT3D_H
#define POINT3D_H


class Point3D
{
public:
   Point3D();
   Point3D(double x, double y, double z);
   bool operator==(const Point3D &rhs);
   ~Point3D();

   double x() const;
   double y() const;
   double z() const;

   void setX(double x);
   void setY(double y);
   void setZ(double z);

private:
   double x_;
   double y_;
   double z_;

};

#endif
