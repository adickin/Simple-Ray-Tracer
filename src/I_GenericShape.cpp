/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include "I_GenericShape.h"
#include "math.h"

static int shapeCount = 0;

static const QString bronzeMaterial = "BRONZE";
static const QString chromeMaterial = "CHROME";
static const QString blueMaterial = "BLUE";
static const QString glassMaterial = "GLASS";

/*
***************************************************************
*
* Default constructor for all shapes, sets the default colour of them
* to Bronze
*
***************************************************************
*/
I_GenericShape::I_GenericShape()
{
   shapeMaterial_.ambient.setRed(0.2125);
   shapeMaterial_.ambient.setGreen(0.1275);
   shapeMaterial_.ambient.setBlue(0.054);

   shapeMaterial_.diffuse.setRed(0.714);
   shapeMaterial_.diffuse.setGreen(0.4284);
   shapeMaterial_.diffuse.setBlue(0.18144);

   shapeMaterial_.specular.setRed(0.393548);
   shapeMaterial_.specular.setGreen(0.271906);
   shapeMaterial_.specular.setBlue(0.166721);

   shapeMaterial_.emission.setRed(0);
   shapeMaterial_.emission.setGreen(0.0);
   shapeMaterial_.emission.setBlue(0);

   shapeMaterial_.shinyness = 25.6;

   shapeMaterial_.localIllumination = 0.6;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.refractedIllumination = 0.2;

   shapeMaterial_.refractionIndex = 3.79;

   shapeId_ = shapeCount;
   shapeCount++;
}

I_GenericShape::~I_GenericShape()
{

}

int I_GenericShape::shapeId()
{
   return shapeId_;
}

Material I_GenericShape::material()
{
   return shapeMaterial_;
}

void I_GenericShape::setMaterial(QString& material)
{
   if(bronzeMaterial == material)
   {
      setMaterialBronze();
   }
   else if(chromeMaterial == material)
   {
      setMaterialChrome();
   }
   else if(glassMaterial == material)
   {
      setMaterialGlass();
   }
   else if(blueMaterial == material)
   {
      setMaterialBlue();
   }
}

/*
***************************************************************
*
*   Chrome    : constant Material_type:= (
            ambient =>        (0.25, 0.25, 0.25, 1.0),
            diffuse =>        (0.4, 0.4, 0.4, 1.0),
            specular =>       (0.774597, 0.774597, 0.774597, 1.0),
            emission =>       (0.0,0.0,0.0,0.0),
            shininess =>      76.8);  
*
***************************************************************
*/
void I_GenericShape::setMaterialChrome()
{
   shapeMaterial_.ambient.setRed(0.25);
   shapeMaterial_.ambient.setGreen(0.25);
   shapeMaterial_.ambient.setBlue(0.25);

   shapeMaterial_.diffuse.setRed(0.4);
   shapeMaterial_.diffuse.setGreen(0.4);
   shapeMaterial_.diffuse.setBlue(0.4);

   shapeMaterial_.specular.setRed(0.774597);
   shapeMaterial_.specular.setGreen(0.774597);
   shapeMaterial_.specular.setBlue(0.774597);

   shapeMaterial_.emission.setRed(0);
   shapeMaterial_.emission.setGreen(0.0);
   shapeMaterial_.emission.setBlue(0);

   shapeMaterial_.shinyness = 76.8;
}

void I_GenericShape::setMaterialBronze()
{
   shapeMaterial_.ambient.setRed(0.2125);
   shapeMaterial_.ambient.setGreen(0.1275);
   shapeMaterial_.ambient.setBlue(0.054);

   shapeMaterial_.diffuse.setRed(0.714);
   shapeMaterial_.diffuse.setGreen(0.4284);
   shapeMaterial_.diffuse.setBlue(0.18144);

   shapeMaterial_.specular.setRed(0.393548);
   shapeMaterial_.specular.setGreen(0.271906);
   shapeMaterial_.specular.setBlue(0.166721);

   shapeMaterial_.emission.setRed(0);
   shapeMaterial_.emission.setGreen(0.0);
   shapeMaterial_.emission.setBlue(0);

   shapeMaterial_.shinyness = 25.6;
}

void I_GenericShape::setMaterialBlue()
{
   shapeMaterial_.ambient.setRed(0.0);
   shapeMaterial_.ambient.setGreen(0.0);
   shapeMaterial_.ambient.setBlue(0.0);

   shapeMaterial_.diffuse.setRed(0.0);
   shapeMaterial_.diffuse.setGreen(0.0);
   shapeMaterial_.diffuse.setBlue(1.0);

   shapeMaterial_.specular.setRed(0.0225);
   shapeMaterial_.specular.setGreen(0.0225);
   shapeMaterial_.specular.setBlue(0.0225);

   shapeMaterial_.emission.setRed(0);
   shapeMaterial_.emission.setGreen(0.0);
   shapeMaterial_.emission.setBlue(0);

   shapeMaterial_.shinyness = 55;
}

/*
***************************************************************
*
*     Glass   : constant Material_type:= (
              ambient   => (0.0, 0.0, 0.0, 1.0),
              diffuse   => (0.588235, 0.670588, 0.729412, 1.0),
              specular  => (0.9, 0.9, 0.9, 1.0),
              emission  => (0.0, 0.0, 0.0, 1.0),
              shininess => 96.0
*
***************************************************************
*/
void I_GenericShape::setMaterialGlass()
{
   shapeMaterial_.ambient.setRed(0.0);
   shapeMaterial_.ambient.setGreen(0.0);
   shapeMaterial_.ambient.setBlue(0.0);

   shapeMaterial_.diffuse.setRed(0.588235);
   shapeMaterial_.diffuse.setGreen(0.670588);
   shapeMaterial_.diffuse.setBlue(0.729412);

   shapeMaterial_.specular.setRed(0.9);
   shapeMaterial_.specular.setGreen(0.9);
   shapeMaterial_.specular.setBlue(0.9);

   shapeMaterial_.emission.setRed(0);
   shapeMaterial_.emission.setGreen(0.0);
   shapeMaterial_.emission.setBlue(0);

   shapeMaterial_.shinyness = 96;

   shapeMaterial_.localIllumination = 0.2;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.refractedIllumination = 0.6;

   shapeMaterial_.refractionIndex = 1.33;
}
