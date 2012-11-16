/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include <QImage>
#include <QStringList>
#include <QLabel>

#include "Window.h"
#include "SideBar.h"

/*
***************************************************************
*
*  Constructor for Main Widnw. 
*
***************************************************************
*/
Window::Window(QWidget *parent) 
:QMainWindow(parent) 
{
   theScene_ = new Scene();
   interfaceSetup();
   setupSignalsAndSlots();

}

Window::~Window() 
{
}

/*
***************************************************************
*
*   sets up all items that appear in the GUI.
*
***************************************************************
*/
void Window::interfaceSetup()
{
   setWindowTitle("Ray Tracer");

   //Menu Bar
   menuBar_ = new QMenuBar(this);
   menuBar_->setGeometry(QRect(0, 0, 810, 26));
   fileMenu_ = new QMenu(menuBar_);
   fileMenu_->setTitle(QString("File"));
   setMenuBar(menuBar_);

   saveAction_ = new QAction(this);
   saveAction_->setText(QString("Save"));
   quitAction_ = new QAction(this);
   quitAction_->setText(QString("Quit"));
   menuBar_->addAction(fileMenu_->menuAction());
   fileMenu_->addAction(saveAction_);
   fileMenu_->addAction(quitAction_);

   centralWidget_ = new QWidget(this);
   horizontalLayout_ = new QHBoxLayout(centralWidget_);

   sideBar_ = new SideBar(centralWidget_);

   imageLabel_ = new QLabel(centralWidget_);
   resetImage();

   
   horizontalLayout_->addWidget(sideBar_);
   horizontalLayout_->addWidget(imageLabel_);
   setCentralWidget(centralWidget_);
}

/*
***************************************************************
*
*   Sets up all signals and slots for  class.
*
***************************************************************
*/
void Window::setupSignalsAndSlots()
{
   
}

void Window::resetImage()
{
   if(image_ != NULL)
   {
      delete image_;
   }

   image_ = new QImage(640, 480, QImage::Format_RGB32);
   theScene_->setImage(image_);
   theScene_->drawScene();
   imageLabel_->setPixmap(QPixmap::fromImage(*image_, Qt::AutoColor));
}

/*
***************************************************************
*
* Exits the application  
*
***************************************************************
*/
void Window::exitApplication(bool exit)
{
   QApplication::exit(exit);
}