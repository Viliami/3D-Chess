#include "pieces.h"

float lpos[4] = {1,0.5,1,0};
int screen_width = 800,screen_height = 800;

//All of the piece variables
King* white_king;
King* black_king;
Queen* white_queen;
Queen* black_queen;
Rook* white_rook_1;
Rook* white_rook_2;
Rook* black_rook_1;
Rook* black_rook_2;
Knight* white_knight_1;
Knight* white_knight_2;
Knight* black_knight_1;
Knight* black_knight_2;
Bishop* white_bishop_1;
Bishop* white_bishop_2;
Bishop* black_bishop_1;
Bishop* black_bishop_2;
Pawn* white_pawn_1;
Pawn* white_pawn_2;
Pawn* white_pawn_3;
Pawn* white_pawn_4;
Pawn* white_pawn_5;
Pawn* white_pawn_6;
Pawn* white_pawn_7;
Pawn* white_pawn_8;
Pawn* black_pawn_1;
Pawn* black_pawn_2;
Pawn* black_pawn_3;
Pawn* black_pawn_4;
Pawn* black_pawn_5;
Pawn* black_pawn_6;
Pawn* black_pawn_7;
Pawn* black_pawn_8;
Piece* board;
Piece* selected_piece = NULL;
extern std::vector<Piece*> pieces;

//helper function to print grid 2d array variable
void print_grid_pieces(void){
    for(int row = 0; row <= 7; row++){
        for(int col = 0; col <= 7; col++){
            int element = grid_pieces[row][col];
            if(element > 0){
                printf("[%i]",element);
            }else if(element == 0){
                printf("[0000]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void loadPieces(){
    white_king = new King("data/models/king.dae","data/textures/white_king.jpg",0,'e',1);
    black_king = new King("data/models/king.dae","data/textures/black_king.jpg",1,'e',8);
    white_queen = new Queen("data/models/queen.dae","data/textures/white_queen.jpg",2,'d',1);
    black_queen = new Queen("data/models/queen.dae","data/textures/black_queen.jpg",3,'d',8);
    white_rook_1 = new Rook("data/models/rook.dae","data/textures/white_rook.jpg",4,'a',1);
    white_rook_2 = new Rook("data/models/rook.dae","data/textures/white_rook.jpg",4,'h',1);
    black_rook_1 = new Rook("data/models/rook.dae","data/textures/black_rook.jpg",5,'a',8);
    black_rook_2 = new Rook("data/models/rook.dae","data/textures/black_rook.jpg",5,'h',8);
    white_bishop_1 = new Bishop("data/models/bishop.dae","data/textures/white_bishop.jpg",6,'c',1);
    white_bishop_2 = new Bishop("data/models/bishop.dae","data/textures/white_bishop.jpg",6,'f',1);
    black_bishop_1 = new Bishop("data/models/bishop.dae","data/textures/black_bishop.jpg",7,'c',8);
    black_bishop_2 = new Bishop("data/models/bishop.dae","data/textures/black_bishop.jpg",7,'f',8);
    white_knight_1 = new Knight("data/models/knight.dae","data/textures/white_knight.jpg",8,'b',1);
    white_knight_2 = new Knight("data/models/knight.dae","data/textures/white_knight.jpg",8,'g',1);
    black_knight_1 = new Knight("data/models/knight.dae","data/textures/black_knight.jpg",9,'b',8);
    black_knight_2 = new Knight("data/models/knight.dae","data/textures/black_knight.jpg",9,'g',8);
    white_pawn_1 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'a',2);
    white_pawn_2 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'b',2);
    white_pawn_3 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'c',2);
    white_pawn_4 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'d',2);
    white_pawn_5 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'e',2);
    white_pawn_6 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'f',2);
    white_pawn_7 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'g',2);
    white_pawn_8 = new Pawn("data/models/pawn.dae","data/textures/white_pawn.jpg",10,'h',2);
    black_pawn_1 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'a',7);
    black_pawn_2 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'b',7);
    black_pawn_3 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'c',7);
    black_pawn_4 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'d',7);
    black_pawn_5 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'e',7);
    black_pawn_6 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'f',7);
    black_pawn_7 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'g',7);
    black_pawn_8 = new Pawn("data/models/pawn.dae","data/textures/black_pawn.jpg",11,'h',7);
    board = new Piece("data/models/board.dae","data/textures/board.jpg",12,'z',0);
    pieces.push_back(white_rook_1);pieces.push_back(white_rook_2);pieces.push_back(white_knight_1);pieces.push_back(white_knight_2);pieces.push_back(white_bishop_1);pieces.push_back(white_bishop_2);pieces.push_back(white_queen);pieces.push_back(white_king);pieces.push_back(white_pawn_1);pieces.push_back(white_pawn_2);pieces.push_back(white_pawn_3);pieces.push_back(white_pawn_4);pieces.push_back(white_pawn_5);pieces.push_back(white_pawn_6);pieces.push_back(white_pawn_7);pieces.push_back(white_pawn_8);pieces.push_back(black_rook_1);pieces.push_back(black_rook_2);pieces.push_back(black_knight_1);pieces.push_back(black_knight_2);pieces.push_back(black_bishop_1);pieces.push_back(black_bishop_2);pieces.push_back(black_queen);pieces.push_back(black_king);pieces.push_back(black_pawn_1);pieces.push_back(black_pawn_2);pieces.push_back(black_pawn_3);pieces.push_back(black_pawn_4);pieces.push_back(black_pawn_5);pieces.push_back(black_pawn_6);pieces.push_back(black_pawn_7);pieces.push_back(black_pawn_8);
    printf("loaded\n");
}

void drawBoard(){
    board->draw();
}

void drawPieces(){
    for(int i = 0; i <= pieces.size()-1; i++){
        glLoadName(1+i);
        pieces.at(i)->draw();
    }

}

void draw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,25,15,
    0,0,0,
    0,1,0);
    glLightfv(GL_LIGHT0,GL_POSITION,lpos);

    glLoadName(99);
    drawBoard();
    drawGrid();
    drawPieces();
    //print_grid_pieces();

    glutSwapBuffers();
}

void resize(int w, int h){
    if(h == 0)
        h = 1;
    float ratio = w*1.0f/h;
    screen_width = w;
    screen_height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);
    gluPerspective(45,ratio,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

void keyEvents(unsigned char key, int x, int y){
    switch(key){
        case 27: //escape key
            glDetachShader(p,v);
            glDetachShader(p,f);
            glDeleteShader(v);
            glDeleteShader(f);
            glDeleteProgram(p);
            printf("shaders freed\n");
            exit(0);
            break;
    }

}

void specialKeys(int key, int x, int y){
    switch(key){
        case GLUT_KEY_F1:
            glDetachShader(p,v);
            glDetachShader(p,f);
            glDeleteShader(v);
            glDeleteShader(f);
            glDeleteProgram(p);
            printf("shaders freed\n");
            exit(0);
            break;
    }
}

void initGL(void){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(10);
}

//calls pick function on the piece at the position specified
void pickPiece(int col, int row){
    for(int i = 0; i<= pieces.size()-1; i++){
        Piece* piece = pieces.at(i);
        if(piece->c_Row == row && piece->c_Col == col && ((piece->color == BLACK && gamestate == BLACK_TURN) || (piece->color == WHITE && gamestate == WHITE_TURN))){
            for(int j = 0; j <= pieces.size()-1; j++){
                pieces.at(j)->unpick();
            }
            piece->pick();
            selected_piece = piece;
            break;
        }
    }
}

//swaps turns from white to black or black to white
void swap_turns(void){
    if(gamestate == WHITE_TURN){
        gamestate = BLACK_TURN;
    }else if(gamestate == BLACK_TURN){
        gamestate = WHITE_TURN;
    }
}

//processes which piece is clicked and which tile is clicked
void list_hits(GLint hits, GLuint *names){
    for(int i = 0; i <= pieces.size()-1; i++){
        pieces.at(i)->unpick();
    }
    bool move_pressed = false;
    for (int i = 0; i < hits; i++){
        int name = (GLubyte)names[i*4+3];
	    if(name >= 1 && name <= 16 && gamestate == WHITE_TURN){
		    pieces[name-1]->pick();
		    selected_piece = pieces[name-1];
	    }else if(name >= 17 && name <= 32 && gamestate == BLACK_TURN){
		    pieces[name-1]->pick();
		    selected_piece = pieces[name-1];
	    }
        if(name == 165){
            move_pressed = true;
            break;
        }
        if(name >= 101){
            printf("Grid clicked\n");
            name -= 100;
            grid_row = 9-(name%8);
            if(grid_row == 9){
                grid_row = 1;
            }
            grid_col = ceil((float)name/8.0f);
            grid_column = column[grid_col-1];
            printf("row = %i col = %i name = %i\n",grid_row,grid_col,name);
        }
    }
    if(move_pressed){
        if((grid_pieces[grid_row-1][grid_col-1] == BLACK && gamestate == WHITE_TURN) || (grid_pieces[grid_row-1][grid_col-1] == WHITE && gamestate == BLACK_TURN)){
            remove_piece(grid_col,grid_row);
        }
        selected_piece->move((unsigned int)grid_col,(unsigned int)grid_row);
        swap_turns();
        clearMovesList();
        selected_piece->unpick();
    }
    printf("position = %c%i\n",grid_column,grid_row);
    pickPiece(grid_col,grid_row);
}

//sets up gl select mode
void gl_select(int x, int y){
    GLuint buff[64] = {0};
    GLint hits, view[4];

    glSelectBuffer(64, buff);

    glGetIntegerv(GL_VIEWPORT, view);

    glRenderMode(GL_SELECT);

    glInitNames();

    glPushName(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x,y,1.0,1.0,view);
    gluPerspective(45,1.0,0.0001,1000.0);

    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
    draw();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    hits = glRenderMode(GL_RENDER);

    list_hits(hits,buff);

    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN){
        gl_select(x,screen_height-y);
    }
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitWindowPosition(-1,-1);
    glutInitWindowSize(screen_width,screen_height);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitContextVersion(2, 1);
    glutCreateWindow("Chess 3D");

    glewExperimental = GL_TRUE;
    glewInit();
    initGL();
    initDLs();
    loadPieces();
    //setShaders();
    gamestate = WHITE_TURN;

    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyEvents);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 1;
}
