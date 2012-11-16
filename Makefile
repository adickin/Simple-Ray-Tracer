#############################################################################
# Makefile for building: tracer
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Nov 16 08:57:15 2012
# Project:  assignment3.pro
# Template: app
# Command: /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake -o Makefile assignment3.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/default -I. -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtOpenGL -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include -I. -I/usr/X11R6/include -I.moc -I.ui
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib64 -lGLU -lglut -lQtOpenGL -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib64 -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = src/main.cpp \
		src/Window.cpp \
		src/SideBar.cpp \
		src/Vector3D.cpp \
		src/Point3D.cpp \
		src/Colour.cpp \
		src/I_GenericShape.cpp \
		src/Sphere.cpp \
		src/Scene.cpp \
		src/Ray.cpp \
		src/Light.cpp .moc/moc_Window.cpp \
		.moc/moc_SideBar.cpp
OBJECTS       = .obj/main.o \
		.obj/Window.o \
		.obj/SideBar.o \
		.obj/Vector3D.o \
		.obj/Point3D.o \
		.obj/Colour.o \
		.obj/I_GenericShape.o \
		.obj/Sphere.o \
		.obj/Scene.o \
		.obj/Ray.o \
		.obj/Light.o \
		.obj/moc_Window.o \
		.obj/moc_SideBar.o
DIST          = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/opengl.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		assignment3.pro
QMAKE_TARGET  = tracer
DESTDIR       = 
TARGET        = tracer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): .ui/ui_SideBar.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: assignment3.pro  /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/default/qmake.conf /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/opengl.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtOpenGL.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl
	$(QMAKE) -o Makefile assignment3.pro
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/opengl.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtOpenGL.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile assignment3.pro

dist: 
	@$(CHK_DIR_EXISTS) .obj/tracer1.0.0 || $(MKDIR) .obj/tracer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .obj/tracer1.0.0/ && $(COPY_FILE) --parents src/Window.h src/SideBar.h src/Vector3D.h src/Point3D.h src/Colour.h src/I_GenericShape.h src/Sphere.h src/Scene.h src/Ray.h src/Light.h .obj/tracer1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/Window.cpp src/SideBar.cpp src/Vector3D.cpp src/Point3D.cpp src/Colour.cpp src/I_GenericShape.cpp src/Sphere.cpp src/Scene.cpp src/Ray.cpp src/Light.cpp .obj/tracer1.0.0/ && $(COPY_FILE) --parents src/SideBar.ui .obj/tracer1.0.0/ && (cd `dirname .obj/tracer1.0.0` && $(TAR) tracer1.0.0.tar tracer1.0.0 && $(COMPRESS) tracer1.0.0.tar) && $(MOVE) `dirname .obj/tracer1.0.0`/tracer1.0.0.tar.gz . && $(DEL_FILE) -r .obj/tracer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: .moc/moc_Window.cpp .moc/moc_SideBar.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) .moc/moc_Window.cpp .moc/moc_SideBar.cpp
.moc/moc_Window.cpp: src/Scene.h \
		src/Point3D.h \
		src/Vector3D.h \
		src/Window.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/Window.h -o .moc/moc_Window.cpp

.moc/moc_SideBar.cpp: .ui/ui_SideBar.h \
		src/SideBar.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/SideBar.h -o .moc/moc_SideBar.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: .ui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) .ui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: .ui/ui_SideBar.h
compiler_uic_clean:
	-$(DEL_FILE) .ui/ui_SideBar.h
.ui/ui_SideBar.h: src/SideBar.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic src/SideBar.ui -o .ui/ui_SideBar.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

.obj/main.o: src/main.cpp src/Window.h \
		src/Scene.h \
		src/Point3D.h \
		src/Vector3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o src/main.cpp

.obj/Window.o: src/Window.cpp src/Window.h \
		src/Scene.h \
		src/Point3D.h \
		src/Vector3D.h \
		src/SideBar.h \
		.ui/ui_SideBar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Window.o src/Window.cpp

.obj/SideBar.o: src/SideBar.cpp src/SideBar.h \
		.ui/ui_SideBar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/SideBar.o src/SideBar.cpp

.obj/Vector3D.o: src/Vector3D.cpp src/Vector3D.h \
		src/Point3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Vector3D.o src/Vector3D.cpp

.obj/Point3D.o: src/Point3D.cpp src/Point3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Point3D.o src/Point3D.cpp

.obj/Colour.o: src/Colour.cpp src/Colour.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Colour.o src/Colour.cpp

.obj/I_GenericShape.o: src/I_GenericShape.cpp src/I_GenericShape.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/I_GenericShape.o src/I_GenericShape.cpp

.obj/Sphere.o: src/Sphere.cpp src/Sphere.h \
		src/I_GenericShape.h \
		src/Point3D.h \
		src/Vector3D.h \
		src/Ray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Sphere.o src/Sphere.cpp

.obj/Scene.o: src/Scene.cpp src/Scene.h \
		src/Point3D.h \
		src/Vector3D.h \
		src/Sphere.h \
		src/I_GenericShape.h \
		src/Ray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Scene.o src/Scene.cpp

.obj/Ray.o: src/Ray.cpp src/Ray.h \
		src/Vector3D.h \
		src/Point3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Ray.o src/Ray.cpp

.obj/Light.o: src/Light.cpp src/Light.h \
		src/Vector3D.h \
		src/Point3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/Light.o src/Light.cpp

.obj/moc_Window.o: .moc/moc_Window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_Window.o .moc/moc_Window.cpp

.obj/moc_SideBar.o: .moc/moc_SideBar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_SideBar.o .moc/moc_SideBar.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

