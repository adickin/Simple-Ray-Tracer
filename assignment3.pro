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
            src/Scene.h \
            src/SideBar.h \
            src/Vector3D.h \
            src/Point3D.h \
            src/Colour.h \
            src/I_GenericShape.h \
            src/Sphere.h \
            src/Plane.h \
            src/Triangle.h \
            src/Quad.h \
            src/Ray.h \
            src/Light.h

            
SOURCES +=  src/main.cpp \
            src/Window.cpp \
            src/Scene.cpp \
            src/SideBar.cpp \
            src/Vector3D.cpp \
            src/Point3D.cpp \
            src/Colour.cpp \
            src/I_GenericShape.cpp \
            src/Sphere.cpp \
            src/Plane.cpp \
            src/Triangle.cpp \
            src/Quad.cpp \
            src/Ray.cpp \
            src/Light.cpp

FORMS +=    src/SideBar.ui
