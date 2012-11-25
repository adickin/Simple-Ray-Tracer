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

//DEFINES ALL OF THE MATERIALS THARE ARE POSSIBLE
static const QString bronzeMaterial = "BRONZE";
static const QString chromeMaterial = "CHROME";
static const QString blueMaterial = "BLUE";
static const QString redMaterial = "RED";
static const QString orangeMaterial = "ORANGE";
static const QString yellowMaterial = "YELLOW";
static const QString greenMaterial = "GREEN";
static const QString indigoMaterial = "INDIGO";
static const QString violetMaterial = "VIOLET";
static const QString whiteMaterial = "WHITE";
static const QString blackMaterial = "BLACK";
static const QString brassMaterial = "BRASS";
static const QString emeraldMaterial = "EMERALD";
static const QString jadeMaterial = "JADE";
static const QString obsidianMaterial = "OBSIDIAN";
static const QString pearlMaterial = "PEARL";
static const QString rubyMaterial = "RUBY";
static const QString turquoiseMaterial = "TURQUOISE";
static const QString rubberMaterial = "RUBBER";
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
   setMaterialBronze();

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

/*
***************************************************************
*
*  Sets this shape's material to be whatever the passed in material 
*  value is.   
*
***************************************************************
*/
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
   else if(orangeMaterial == material)
   {
      setMaterialOrange();
   }
   else if(yellowMaterial == material)
   {
      setMaterialYellow();
   }
   else if(greenMaterial == material)
   {
      setMaterialGreen();
   }
   else if(indigoMaterial == material)
   {
      setMaterialIndigo();
   }
   else if(violetMaterial == material)
   {
      setMaterialViolet();
   }
   else if(whiteMaterial == material)
   {
      setMaterialWhite();
   }
   else if(blackMaterial == material)
   {
      setMaterialBlack();
   }
   else if(brassMaterial == material)
   {
      setMaterialBrass();
   }
   else if(emeraldMaterial == material)
   {
      setMaterialEmerald();
   }
   else if(jadeMaterial == material)
   {
      setMaterialJade();
   }
   else if(obsidianMaterial == material)
   {
      setMaterialObsidian();
   }
   else if(pearlMaterial == material)
   {
      setMaterialPearl();
   }
   else if(rubyMaterial == material)
   {
      setMaterialRuby();
   }
   else if(turquoiseMaterial == material)
   {
      setMaterialTurquoise();
   }
   else if(rubberMaterial == material)
   {
      setMaterialRubber();
   }

}

/*
***************************************************************
*
*  Sets the shapes material to Chrome
*
***************************************************************
*/
void I_GenericShape::setMaterialChrome()
{
   shapeMaterial_.ambient.setColour(0.25, 0.25, 0.25);
   shapeMaterial_.diffuse.setColour(0.4, 0.4, 0.4);
   shapeMaterial_.specular.setColour(0.774597, 0.774597, 0.774597);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 76.8;
}

/*
***************************************************************
*
* Sets the shape material to bronze  
*
***************************************************************
*/
void I_GenericShape::setMaterialBronze()
{
   shapeMaterial_.ambient.setColour(0.2125, 0.1275, 0.054);
   shapeMaterial_.diffuse.setColour(0.714, 0.4284, 0.18144);
   shapeMaterial_.specular.setColour(0.393548, 0.271906, 0.166721);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 25.6;
}

/*
***************************************************************
*
* Sets the shapes material to blue  
*
***************************************************************
*/
void I_GenericShape::setMaterialBlue()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.0, 0.0, 1.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0255, 0.0255);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 55;
}

/*
***************************************************************
*
*  Sets the shapes material to glass
*
***************************************************************
*/
void I_GenericShape::setMaterialGlass()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.588235, 0.670588, 0.729412);
   shapeMaterial_.specular.setColour(0.9, 0.9, 0.9);

   shapeMaterial_.localIllumination = 0.2;
   shapeMaterial_.reflectedIllumination = 0.8;
   shapeMaterial_.shinyness = 96;
}

void I_GenericShape::setMaterialRed()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(1.0, 0.0, 0.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialOrange()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.992157, 0.513726, 0.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialYellow()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(1.0, 0.964706, 0.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialGreen()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.0, 1.0, 0.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialIndigo()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.0980392, 0.0, 0.458824);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialViolet()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.635294, 0.0, 1.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialWhite()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.992157, 0.992157, 0.992157);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialBlack()
{
   shapeMaterial_.ambient.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.diffuse.setColour(0.0, 0.0, 0.0);
   shapeMaterial_.specular.setColour(0.0225, 0.0225, 0.0225);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialBrass()
{
   shapeMaterial_.ambient.setColour(0.329412, 0.223529, 0.027451);
   shapeMaterial_.diffuse.setColour(0.780392, 0.568627, 0.7113725);
   shapeMaterial_.specular.setColour(0.992157, 0.941176, 0.807843);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 27.8974;
}

void I_GenericShape::setMaterialEmerald()
{
   shapeMaterial_.ambient.setColour(0.0215, 0.1745, 0.0215);
   shapeMaterial_.diffuse.setColour(0.07568, 0.61424, 0.07568);
   shapeMaterial_.specular.setColour(0.633, 0.727811, 0.633);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 76.8;
}

void I_GenericShape::setMaterialJade()
{
   shapeMaterial_.ambient.setColour(0.135, 0.2225, 0.1575);
   shapeMaterial_.diffuse.setColour(0.54, 0.89, 0.63);
   shapeMaterial_.specular.setColour(0.316228, 0.316228, 0.316228);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialObsidian()
{
   shapeMaterial_.ambient.setColour(0.05375, 0.05, 0.06625);
   shapeMaterial_.diffuse.setColour(0.18275, 0.17, 0.22525);
   shapeMaterial_.specular.setColour(0.332741, 0.328634, 0.346435);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 38.4;
}

void I_GenericShape::setMaterialPearl()
{
   shapeMaterial_.ambient.setColour(0.25, 0.20725, 0.20725);
   shapeMaterial_.diffuse.setColour(1.0, 0.829, 0.829);
   shapeMaterial_.specular.setColour(0.296648, 0.296648, 0.296648);

   shapeMaterial_.localIllumination = 0.90;
   shapeMaterial_.reflectedIllumination = 0.1;
   shapeMaterial_.shinyness = 11.264;
}

void I_GenericShape::setMaterialRuby()
{
   shapeMaterial_.ambient.setColour(0.1745, 0.01175, 0.01175);
   shapeMaterial_.diffuse.setColour(0.61424, 0.04136, 0.04136);
   shapeMaterial_.specular.setColour(0.727811, 0.626959, 0.626959);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 76.8;
}

void I_GenericShape::setMaterialTurquoise()
{
   shapeMaterial_.ambient.setColour(0.1, 0.18725, 0.1745);
   shapeMaterial_.diffuse.setColour(0.396, 0.74151, 0.69102);
   shapeMaterial_.specular.setColour(0.297254, 0.30829, 0.306678);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 12.8;
}

void I_GenericShape::setMaterialRubber()
{
   shapeMaterial_.ambient.setColour(0.02, 0.02, 0.02);
   shapeMaterial_.diffuse.setColour(0.01, 0.01, 0.01);
   shapeMaterial_.specular.setColour(0.4, 0.4, 0.4);

   shapeMaterial_.localIllumination = 0.8;
   shapeMaterial_.reflectedIllumination = 0.2;
   shapeMaterial_.shinyness = 10.0;
}
