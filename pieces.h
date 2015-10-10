#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "textfile.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <vector>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7

#define BLACK 1337
#define WHITE 6969

enum GAMESTATE : int{
    MENU,WHITE_TURN,BLACK_TURN,WHITE_WIN,BLACK_WIN,TIE
};

extern int highlighted_tiles[28][2];

class Piece{
    public:
        char column[9] = {'a','b','c','d','e','f','g','h','z'};
        int c_Row, c_Col; //current row and current column
        char c_Column;
        GLfloat *vertexArray,*normalArray,*uvArray,angle;
        int value, numVerts;
        unsigned int textureNumber;
        float var_swag;
	    bool picked = false;
        int color;

        explicit Piece(const char* modelFile, const char* textureFile,int textureNum,char col, int row);
        ~Piece(){};
        virtual void draw();
	    virtual void listMoves(void);
	    void pick(void);
	    void unpick(void);
        void changePos(unsigned int col, unsigned int row);
        void changePos(char col, unsigned int row);
};

class King : public Piece{
    public:
        King(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("King loaded\n");
            value = 9999;
        };
        ~King();
};

class Queen : public Piece{
    public:
        Queen(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Queen loaded\n");
            value = 9;
        };
        ~Queen();
};

class Rook : public Piece{
    public:
        Rook(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Rook loaded\n");
            value = 5;
        };
        ~Rook();
};

class Knight : public Piece{
    public:
        Knight(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Knight loaded\n");
            value = 3;
            var_swag = 0.0f;
        };
        ~Knight();
        void draw();
};

class Bishop : public Piece{
    public:
        Bishop(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Bishop loaded\n");
            value = 3;
        };
        ~Bishop();
};

class Pawn : public Piece{
    public:
        Pawn(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Pawn loaded\n");
            value = 1;
        };
        ~Pawn();
        void listMoves(void);
};
