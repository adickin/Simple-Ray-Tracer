

#ifndef POINT3D_H
#define POINT3D_H

/*
***************************************************************
*
* Represents a point in a 3D setting.  Has functions to 
* get and set the location of the point.   
*
***************************************************************
*/
class Point3D
{
public:
   Point3D();
   Point3D(double x, double y, double z);
   bool operator==(const Point3D &rhs);
   Point3D operator-(const Point3D& rhs);
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
