#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

bool loadOBJ(const char* filePath,float *&vertexArray,float *&normalArray,float *&uvArray,int &numVerts);
bool loadGLTexture(const char* filePath, unsigned int textureNum, GLuint (&texture)[32]);
