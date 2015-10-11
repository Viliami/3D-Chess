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

#define WHITE_ROOK1 1
#define WHITE_ROOK2 2
#define WHITE_KNIGHT1 3
#define WHITE_KNIGHT2 4
#define WHITE_BISHOP1 5
#define WHITE_BISHOP2 6
#define WHITE_QUEEN 7
#define WHITE_KING 8
#define WHITE_PAWN1 9
#define WHITE_PAWN2 10
#define WHITE_PAWN3 11
#define WHITE_PAWN4 12
#define WHITE_PAWN5 13
#define WHITE_PAWN6 14
#define WHITE_PAWN7 15
#define WHITE_PAWN8 16

#define BLACK_ROOK1 17
#define BLACK_ROOK2 18
#define BLACK_KNIGHT1 19
#define BLACK_KNIGHT2 20
#define BLACK_BISHOP1 21
#define BLACK_BISHOP2 22
#define BLACK_QUEEN 23
#define BLACK_KING 24
#define BLACK_PAWN1 25
#define BLACK_PAWN2 26
#define BLACK_PAWN3 27
#define BLACK_PAWN4 28
#define BLACK_PAWN5 29
#define BLACK_PAWN6 30
#define BLACK_PAWN7 31
#define BLACK_PAWN8 32

enum GAMESTATE : int{
    MENU,WHITE_TURN,BLACK_TURN,WHITE_WIN,BLACK_WIN,TIE
};
extern int grid_pieces[8][8];

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
        void move(unsigned int col, unsigned int row);
        void move(char col, unsigned int row);
};

class King : public Piece{
    public:
        King(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("King loaded\n");
            value = 9999;
        };
        ~King();
        void listMoves(void);
};

class Queen : public Piece{
    public:
        Queen(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Queen loaded\n");
            value = 9;
        };
        ~Queen();
        void listMoves(void);
};

class Rook : public Piece{
    public:
        Rook(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Rook loaded\n");
            value = 5;
        };
        ~Rook();
        void listMoves(void);
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
        void listMoves(void);
};

class Bishop : public Piece{
    public:
        Bishop(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Bishop loaded\n");
            value = 3;
        };
        ~Bishop();
        void listMoves(void);
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
