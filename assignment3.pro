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
HEADERS +=  src/GLWidget.h \
            src/Window.h \
            src/SideBar.h \
            src/Vector3D.h \
            src/Point3D.h \
            src/Colour.h \
            src/GenericShape.h

            
SOURCES +=  src/GLWidget.cpp \
            src/main.cpp \
            src/Window.cpp \
            src/SideBar.cpp \
            src/Vector3D.cpp \
            src/Point3D.cpp \
            src/Colour.cpp \
            src/GenericShape.cpp

FORMS +=    src/SideBar.ui
