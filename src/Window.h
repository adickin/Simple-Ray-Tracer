

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtGui>
#include <QList>

class SideBar;
class QImage;
class QLabel;
#include "Scene.h"

/*
***************************************************************
*
*  Main window of the application, sets up all the UI elements
*  as well as the glWidget_.  Sets up all neccasary signals
*  and slots.
*
***************************************************************
*/
class Window : public QMainWindow 
{
   Q_OBJECT

public:
   Window(QWidget *parent = NULL);
   ~Window();

public slots:
   void resetImage();
   void saveImage();
   void updateLabel();
   void beginDrawing();

signals:
   void start();
   void loadSceneRequested(QString&);

private://methods
   void interfaceSetup();
   void setupSignalsAndSlots();

private slots://members
   void openScene();
   void exitApplication(bool exit);

private:

//Menu Bar
   QMenuBar* menuBar_;
   QMenu* fileMenu_;
   QAction* saveAction_;
   QAction* quitAction_;

//Layouts
   QWidget* centralWidget_;
   QHBoxLayout* horizontalLayout_;

   QLabel* imageLabel_;
   QImage* image_;
   SideBar* sideBar_;

   Scene* theScene_;

};

#endif