# 3D-Chess
3D chess game made in OpenGL

![Alt text](https://cloud.githubusercontent.com/assets/13442473/10416393/5e9edbda-7072-11e5-89e5-b0e79c520706.png "Lines aren't rendered properly in this image")

### Dependencies
- Freeglut3 (Opensource version of GLUT).
- GLEW (GL extensions wrangler library).
- Assimp model loader.
- SOIL image loader.
- A compiler with at least C++11 support.

### Compiling the program
- Using make file:
```
make
```
- Using compiler flags:
```
-lGL -lGLU -lglut -lGLEW -lassimp -lSOIL -w -std=c++11
```
- Example:
```
g++ main.cpp pieces.cpp textfile.cpp -lGL -lGLU -lglut -lGLEW -lassimp -lSOIL -w -std=c++11 -o Chess3D
```

### Linux install commands for each dependency
```
//Universe repo needed for SOIL and Assimp installations
sudo apt-add repository universe
sudo apt-get update

sudo apt-get install freeglut3-dev libglew1.6-dev libassimp-dev libsoil-dev
```

### 3D models

Models used in this game are from 3dvia.com and are all made by user jdelrio: http://www.3dvia.com/users/jdelrio

They are used under the following license: http://creativecommons.org/licenses/by/2.5/
