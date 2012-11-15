/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>
#include <GL/glut.h>

#include "GLWidget.h"

/*
***************************************************************
*
* Constructor for GLWidget  
*
***************************************************************
*/
GLWidget::GLWidget(QWidget *parent) 
   :QGLWidget (parent) 
{
   setMinimumSize(500, 500);
}

/*
***************************************************************
*
* Destructor  
*
***************************************************************
*/
GLWidget::~GLWidget() 
{
}

/*
***************************************************************
*
* Called once when the GLWidget is created.
*
***************************************************************
*/
void GLWidget::initializeGL() 
{
   glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_RESCALE_NORMAL);

   glClearColor(0.3,0.6,0.5,0.5);
}

/*
***************************************************************
*
*  Called everytime the GL window is resized.  
*
***************************************************************
*/
void GLWidget::resizeGL(int width, int height) 
{
   windowWidth_ = width;
   windowHeight_ = height;
   glViewport(0,0,width, height);
}

/*
***************************************************************
*
*  Function called everytime updateGL() is called  
*
***************************************************************
*/
void GLWidget::paintGL() 
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();


   glFlush();
}

/*
***************************************************************
*
*  Called whenever a mouse button is clicked  
*
***************************************************************
*/
void GLWidget::mousePressEvent(QMouseEvent *event) 
{
   if (event->button() == Qt::LeftButton) 
   {

   }
}

/*
***************************************************************
*
*  Called whenever a mouse moves on top of the widget  
*
***************************************************************
*/
void GLWidget::mouseMoveEvent(QMouseEvent *event) 
{

   updateGL();
}

/*
***************************************************************
*
*   Called whenever a keyboard key is pressed
*
***************************************************************
*/
void GLWidget::keyPressEvent(QKeyEvent *event) 
{
   if (event->key() == Qt::Key_Q) 
   {
      close();
   }
}

/*
***************************************************************
*
*  Called whever the mouse wheel is moved forward or back,
*  performs uniform scaling on the model.  
*
***************************************************************
*/
void GLWidget::wheelEvent(QWheelEvent *event) 
{
   if (event->orientation() == Qt::Vertical) 
   {

      updateGL();
   }
}
