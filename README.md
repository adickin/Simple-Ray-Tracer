Adam Dickin
10016859
Assignment 3

Code Reuse: 
-Adapted some classes from Assignment2 for use with this assignment
-Used material colours from http://globe3d.sourceforge.net/g3d_html/gl-materials__ads.htm

Compiling:
1. navigate into the folder this readme is in
2. Run "qmake"
3. Run "make"
4. Run "./tracer"

Data Structures:
-Used QLists to hold the shapes and lights
-Used class notes for algorithms for ray casting/traceing

User Manual:
-Application uses .scn files to read in a scene description for the shapes and lights.  A sample scene
can be seen by going to ./scenes/sample.scn.  This file describes how the format works and is read in by the application.  
-Clicking the Open A Scene button will open a file browser to select a scene.  After scene selection you will be able to see the raytracer in action.  
-If the scene is acceptable select the File option from the top bar and click save.  You will be preseneted with a file browser where you can specify the filename.  Always be sure to add your text and add .jpg or the file might not save correctly.

Bonuses:
Implemented the read in scene file to draw a scene

Images:
*all included images have phong lighting.

Zelda.jpg - Just a simple drawing showing triangles and quads with shadows and 2 lights
Scene2.jpg - Random scene showing quads, triangles and spheres with shadows and reflection with 3 lights
Spheres.jpg - Scene composed entirly of spheres and 6 lights.  Camera was moved to the right and down for this scene to get the full effect.  Camera position is usually fixed to 0,0,850