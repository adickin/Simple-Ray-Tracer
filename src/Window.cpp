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

void Window::updateLabel()
{
   //fprintf(stderr, "getting here\n");
   imageLabel_->setPixmap(QPixmap::fromImage(*image_, Qt::AutoColor));
   imageLabel_->repaint();
   QCoreApplication::processEvents();
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
   connect(theScene_, SIGNAL(finishedDrawing()), this, SLOT(updateLabel()));
   connect(sideBar_->ui_.openSceneButton, SIGNAL(released())
      , this, SLOT(openScene()));
   connect(saveAction_, SIGNAL(triggered(bool)), this, SLOT(resetImage()));
   connect(quitAction_, SIGNAL(triggered(bool)), this, SLOT(exitApplication(bool)));
}

void Window::resetImage()
{
   if(image_ != NULL)
   {
      for(int x = 0; x < 640; x++)
      {
         for(int y = 0; y < 480; y++)
         {
            image_->setPixel(x, y, qRgb(0, 0, 0));
         }
      }
   }
   else
   {
     image_ = new QImage(640, 480, QImage::Format_RGB32);
   }

   theScene_->setImage(image_);
}

void Window::openScene()
{
   QString fileName = QFileDialog::getOpenFileName(this, QString("Select Scene"), QString("./")
                     , QString("SCENES (*.scn *.SCN"));
   theScene_->loadScene(fileName);
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
