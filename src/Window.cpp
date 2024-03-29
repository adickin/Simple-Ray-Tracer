

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
* updates the label that contains the scenes image.  
*
***************************************************************
*/
void Window::updateLabel()
{
   imageLabel_->setPixmap(QPixmap::fromImage(*image_, Qt::AutoColor));
   imageLabel_->repaint();
   QCoreApplication::processEvents();
}

/*
***************************************************************
*
* starts the ray tracer on another thread so that GUI remains responsive  
*
***************************************************************
*/
void Window::beginDrawing()
{
   theScene_->start();

   while(theScene_->isRunning())
   {
      updateLabel();
   }
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
   menuBar_->setGeometry(QRect(0, 0, 600, 26));
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
   connect(theScene_, SIGNAL(sceneLoadFinished()), this, SLOT(beginDrawing()));
   connect(this, SIGNAL(loadSceneRequested(QString &)), theScene_, SLOT(loadScene(QString &)));
   connect(sideBar_->ui_.openSceneButton, SIGNAL(released())
      , this, SLOT(openScene()));
   connect(saveAction_, SIGNAL(triggered(bool)), this, SLOT(saveImage()));
   connect(quitAction_, SIGNAL(triggered(bool)), this, SLOT(exitApplication(bool)));
}

/*
***************************************************************
*
* Resets the image back to black  
*
***************************************************************
*/
void Window::resetImage()
{
   if(image_ != NULL)
   {
      image_->fill(QColor("Black"));
   }
   else
   {
     image_ = new QImage(640, 480, QImage::Format_RGB32);
   }

   theScene_->setImage(image_);
   updateLabel();
}

/*
***************************************************************
*
* Opesn up a file browser to allow a user to pick a scene file to load.  
*
***************************************************************
*/
void Window::openScene()
{
   QString fileName = QFileDialog::getOpenFileName(this, QString("Select Scene"), QString("./scenes")
                     , QString("SCENES (*.scn *.SCN"));
   resetImage();
   emit loadSceneRequested(fileName);
}

/*
***************************************************************
*
* Opens up a file dialog that allows a user to pick a save directory.  
*
***************************************************************
*/
void Window::saveImage()
{
   if(image_)
   {
      QString fileName = QFileDialog::getSaveFileName(this, QString("Save File"), QString("./savedImages")
                        ,QString("Images (*.png, *.jpg)"));

      image_->save(fileName);
   }
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
