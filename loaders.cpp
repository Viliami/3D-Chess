#include "loaders.h"

bool loadOBJ(const char* filePath,float *&vertexArray,float *&normalArray,float *&uvArray,int &numVerts){
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filePath, aiProcessPreset_TargetRealtime_Fast);
    if(!scene){
        printf("failed to load\n");
        return false;
    }
    aiMesh *mesh = scene->mMeshes[0];
    numVerts = mesh->mNumFaces*3;
    vertexArray = new float[mesh->mNumFaces*3*3];
    normalArray = new float[mesh->mNumFaces*3*3];
    uvArray = new float[mesh->mNumFaces*3*2];

    for(unsigned int i = 0; i<mesh->mNumFaces;i++){
        const aiFace& face = mesh->mFaces[i];
        for(int j = 0; j < 3; j++){
            aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
            memcpy(uvArray,&uv,sizeof(float)*2);
            uvArray+=2;

            aiVector3D pos = mesh->mVertices[face.mIndices[j]];
            memcpy(vertexArray,&pos,sizeof(float)*3);
            vertexArray+=3;

            aiVector3D normal = mesh->mNormals[face.mIndices[j]];
            memcpy(normalArray, &normal, sizeof(float)*3);
            normalArray+=3;
        }
    }

    uvArray-=mesh->mNumFaces*3*2;
    normalArray-=mesh->mNumFaces*3*3;
    vertexArray-=mesh->mNumFaces*3*3;
}

bool loadGLTexture(const char* filePath, unsigned int textureNum, GLuint (&texture)[32]){
    texture[textureNum] = SOIL_load_OGL_texture(
    filePath,
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
    );

    if(texture[textureNum] == 0){
        printf("Could not load texture\n");
        return false;
    }

    glBindTexture(GL_TEXTURE_2D, texture[textureNum]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    return true;
}
