######################################################################
# Adam Dickin
######################################################################

TEMPLATE = app
TARGET = tracer
DEPENDPATH += .
INCLUDEPATH += .
QT += opengl
LIBS += -lGLU -lglut

OBJECTS_DIR = ./.obj
MOC_DIR = ./.moc
UI_DIR = ./.ui


# Input
HEADERS +=  src/Window.h \
            src/SideBar.h \
            src/Vector3D.h \
            src/Point3D.h \
            src/Colour.h \
            src/I_GenericShape.h \
            src/Sphere.h \
            src/Scene.h

            
SOURCES +=  src/main.cpp \
            src/Window.cpp \
            src/SideBar.cpp \
            src/Vector3D.cpp \
            src/Point3D.cpp \
            src/Colour.cpp \
            src/I_GenericShape.cpp \
            src/Sphere.cpp \
            src/Scene.cpp

FORMS +=    src/SideBar.ui
