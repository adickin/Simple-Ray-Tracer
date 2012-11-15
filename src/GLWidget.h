/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

/*
***************************************************************
*
*  
*
***************************************************************
*/
class GLWidget : public QGLWidget 
{
   Q_OBJECT

public:
   GLWidget(QWidget *parent);
   ~GLWidget();

public slots:
   

protected:
   void initializeGL();
   void resizeGL(int width, int height);
   void paintGL();
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void keyPressEvent(QKeyEvent *event);
   void wheelEvent(QWheelEvent *event);

private:
   int windowWidth_;
   int windowHeight_;

};

#endif

