/*
*********************************************************************
*  Adam Dickin
*  10016859
*  CPSC 453
*  Assignment 3
*********************************************************************
*/

#include <QStringList>

#include "Window.h"
#include "GLWidget.h"
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
   setWindowTitle("Model Viewer");

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

   glWidget_ = new GLWidget(centralWidget_);
   
   horizontalLayout_->addWidget(sideBar_);
   horizontalLayout_->addWidget(glWidget_);
   setCentralWidget(centralWidget_);
}

/*
***************************************************************
*
*   Sets up all signals and slots for this class.
*
***************************************************************
*/
void Window::setupSignalsAndSlots()
{
   
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