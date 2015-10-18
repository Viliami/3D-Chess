#include <GL/glew.h>
#include <GL/freeglut.h>
#include "textfile.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <vector>
#include <algorithm>

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

//global variables
extern int grid_pieces[8][8],grid_row, grid_col,highlighted_tiles[56][2];
extern char column[9],grid_column;
extern GAMESTATE gamestate; //enum which stores current state, like player turns and menu
extern GLuint p,f,v; //program, frag shader, vert shader

//gloval functions
extern void setShaders(void);
extern void drawGrid(void);
extern void initDLs(void);
extern void clearMovesList(void);

class Piece{
    public:
        int c_Row, c_Col, color, textureNumber, value, numVerts; //c_Row = current row c_Col = current column
        char c_Column;
        GLfloat *vertexArray,*normalArray,*uvArray;
        float var_swag;
	    bool picked = false, en_passant = false, has_moved = false;

        explicit Piece(const char* modelFile, const char* textureFile,int textureNum,char col, int row);
        ~Piece(){free(vertexArray);free(normalArray);free(uvArray);};

        virtual void draw(bool side_piece = false, float x = 0.0f, float y = 0.0f);
	    virtual void listMoves(void);
        virtual void move(unsigned int col, unsigned int row);
        virtual void move(char col, unsigned int row);

	    void pick(void);
	    void unpick(void);
        void createMoveList(int col_inc, int row_inc, int min_array);
        void render(void);
};

extern std::vector<Piece*> pieces,side_pieces;

extern Piece* piece_at(int col, int row);
extern void remove_piece(int col, int row);

class King : public Piece{
    public:
        King(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("King loaded\n");
            value = 9999;
        };
        ~King();
        void listMoves(void);
        void move(unsigned int col, unsigned int row);
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
        void draw(bool side_piece = false, float x = 0.0f, float y = 0.0f);
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
        bool firstMove = true;

        Pawn(const char* modelFile, const char* textureFile,int textureNum,char col, int row) : Piece(modelFile, textureFile, textureNum,col,row){
            printf("Pawn loaded\n");
            value = 1;
        };
        ~Pawn();
        void listMoves(void);
        void move(unsigned int col, unsigned int row);
        void check_promotion(void);
};
