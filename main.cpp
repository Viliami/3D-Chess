#include "pieces.h"

extern GLuint p,f,v;
float data[] = {
    0,1,0,
    -1,-1,0,
    1,-1,0
};
float lpos[4] = {1,0.5,1,0};
int screen_width = 600, screen_height = 600;
extern int grid_row, grid_col;
extern char grid_column;
extern GAMESTATE gamestate;
//extern int highlighted_tiles[28][2];

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
std::vector<Piece*> pieces;

float y_level = 0.0f;

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


extern void setShaders(void);
extern void drawGrid(void);
extern void initDLs(void);

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
    pieces.push_back(white_king);pieces.push_back(black_king);pieces.push_back(white_queen);pieces.push_back(black_queen);pieces.push_back(white_rook_1);pieces.push_back(white_rook_2);pieces.push_back(black_rook_1);pieces.push_back(black_rook_2);pieces.push_back(white_knight_1);pieces.push_back(white_knight_2);pieces.push_back(black_knight_1);pieces.push_back(black_knight_2);pieces.push_back(white_bishop_1);pieces.push_back(white_bishop_2);pieces.push_back(black_bishop_1);pieces.push_back(black_bishop_2);pieces.push_back(white_pawn_1);pieces.push_back(white_pawn_2);pieces.push_back(white_pawn_3);pieces.push_back(white_pawn_4);pieces.push_back(white_pawn_5);pieces.push_back(white_pawn_6);pieces.push_back(white_pawn_7);pieces.push_back(white_pawn_8);pieces.push_back(black_pawn_1);pieces.push_back(black_pawn_2);pieces.push_back(black_pawn_3);pieces.push_back(black_pawn_4);pieces.push_back(black_pawn_5);pieces.push_back(black_pawn_6);pieces.push_back(black_pawn_7);pieces.push_back(black_pawn_8);
    printf("loaded\n");
}

void drawBoard(){
    board->draw();
}

void drawPieces(){
    //white pieces
    glLoadName(WHITE_ROOK1);    white_rook_1->draw();
    glLoadName(WHITE_KNIGHT1);  white_knight_1->draw();
    glLoadName(WHITE_BISHOP1);  white_bishop_1->draw();
    glLoadName(WHITE_QUEEN);    white_queen->draw();
    glLoadName(WHITE_KING);     white_king->draw();
    glLoadName(WHITE_BISHOP2);  white_bishop_2->draw();
    glLoadName(WHITE_KNIGHT2);  white_knight_2->draw(); 
    glLoadName(WHITE_ROOK2);    white_rook_2->draw();
    glLoadName(WHITE_PAWN1);    white_pawn_1->draw();
    glLoadName(WHITE_PAWN2);    white_pawn_2->draw();
    glLoadName(WHITE_PAWN3);    white_pawn_3->draw();
    glLoadName(WHITE_PAWN4);    white_pawn_4->draw();
    glLoadName(WHITE_PAWN5);    white_pawn_5->draw();
    glLoadName(WHITE_PAWN6);    white_pawn_6->draw();
    glLoadName(WHITE_PAWN7);    white_pawn_7->draw();
    glLoadName(WHITE_PAWN8);    white_pawn_8->draw();

    //black pieces
    glLoadName(BLACK_ROOK1);    black_rook_1->draw();
    glLoadName(BLACK_KNIGHT1);  black_knight_1->draw();
    glLoadName(BLACK_BISHOP1);  black_bishop_1->draw();
    glLoadName(BLACK_QUEEN);    black_queen->draw();
    glLoadName(BLACK_KING);     black_king->draw();
    glLoadName(BLACK_BISHOP2);  black_bishop_2->draw();
    glLoadName(BLACK_KNIGHT2);  black_knight_2->draw();
    glLoadName(BLACK_ROOK2);    black_rook_2->draw();
    glLoadName(BLACK_PAWN1);    black_pawn_1->draw();
    glLoadName(BLACK_PAWN2);    black_pawn_2->draw();
    glLoadName(BLACK_PAWN3);    black_pawn_3->draw();
    glLoadName(BLACK_PAWN4);    black_pawn_4->draw();
    glLoadName(BLACK_PAWN5);    black_pawn_5->draw();
    glLoadName(BLACK_PAWN6);    black_pawn_6->draw();
    glLoadName(BLACK_PAWN7);    black_pawn_7->draw();
    glLoadName(BLACK_PAWN8);    black_pawn_8->draw();

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
        case GLUT_KEY_UP:
            y_level += 0.1f;
            printf("y_level = %f\n",y_level);
            break;
        case GLUT_KEY_DOWN:
            y_level -= 0.01f;
            printf("y_level = %f\n",y_level);
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

void checkPossibleMoves(){
    if(selected_piece != NULL){
        for(int i = 0; i < sizeof(highlighted_tiles)/sizeof(highlighted_tiles[0]); i++){
            printf("i = %i\n",i);
            if(highlighted_tiles[i][0] > 0){
                if(highlighted_tiles[i][0] == grid_row && highlighted_tiles[i][1] == grid_col){
                    printf("clicked on possible tile\n");
                }
                printf("has not clicked on this possible tile\n");
            }
        }
    }
}

void list_hits(GLint hits, GLuint *names){
    printf("%d hits:\n", hits);
    for(int i = 0; i <= pieces.size()-1; i++){
        pieces.at(i)->unpick();
    }
    for (int i = 0; i < hits; i++){
        int name = (GLubyte)names[i*4+3];
        printf("Name on stack: %d\n", name);
        switch(gamestate){
            case WHITE_TURN:
                switch(name){
                    case WHITE_ROOK1:
                        printf("White rook 1\n");
                        white_rook_1->pick();
                        selected_piece = white_rook_1;
                        break;
                    case WHITE_ROOK2:
                        printf("White rook 2\n");
                        white_rook_2->pick();
                        selected_piece = white_rook_2;
                        break;
                    case WHITE_KNIGHT1:
                        printf("White knight 1\n");
                        white_knight_1->pick();
                        selected_piece = white_knight_1;
                        break;
                    case WHITE_KNIGHT2:
                        printf("White knight 2\n");
                        white_knight_2->pick();
                        selected_piece = white_knight_2;
                        break;
                    case WHITE_BISHOP1:
                        printf("White bishop 1\n");
                        white_bishop_1->pick();
                        selected_piece = white_bishop_1;
                        break;
                    case WHITE_BISHOP2:
                        printf("White bishop 2\n");
                        white_bishop_2->pick();
                        selected_piece = white_bishop_2;
                        break;
                    case WHITE_QUEEN:
                        printf("White queen\n");
                        white_queen->pick();
                        selected_piece = white_queen;
                        break;
                    case WHITE_KING:
                        printf("White king\n");
                        white_king->pick();
                        selected_piece = white_king;
                        break;
                    case WHITE_PAWN1:
                        printf("White pawn 1\n");
                        white_pawn_1->pick();
                        selected_piece = white_pawn_1;
                        break;
                    case WHITE_PAWN2:
                        printf("White pawn 2\n");
                        white_pawn_2->pick();
                        selected_piece = white_pawn_2;
                        break;
                    case WHITE_PAWN3:
                        printf("White pawn 3\n");
                        white_pawn_3->pick();
                        selected_piece = white_pawn_3;
                        break;
                    case WHITE_PAWN4:
                        printf("White pawn 4\n");
                        white_pawn_4->pick();
                        selected_piece = white_pawn_4;
                        break;
                    case WHITE_PAWN5:
                        printf("White pawn 5\n");
                        white_pawn_5->pick();
                        selected_piece = white_pawn_5;
                        break;
                    case WHITE_PAWN6:
                        printf("White pawn 6\n");
                        white_pawn_6->pick();
                        selected_piece = white_pawn_6;
                        break;
                    case WHITE_PAWN7:
                        printf("White pawn 7\n");
                        white_pawn_7->pick();
                        selected_piece = white_pawn_7;
                        break;
                    case WHITE_PAWN8:
                        printf("White pawn 8\n");
                        white_pawn_8->pick();
                        selected_piece = white_pawn_8;
                        break;
                }
                break;
            case BLACK_TURN:
                switch(gamestate){
                    case BLACK_ROOK1:
                        printf("black rook 1\n");
                        black_rook_1->pick();
                        selected_piece = black_rook_1;
                        break;
                    case BLACK_ROOK2:
                        printf("black rook 2\n");
                        black_rook_2->pick();
                        selected_piece = black_rook_2;
                        break;
                    case BLACK_KNIGHT1:
                        printf("black knight 1\n");
                        black_knight_1->pick();
                        selected_piece = black_knight_1;
                        break;
                    case BLACK_KNIGHT2:
                        printf("black knight 2\n");
                        black_knight_2->pick();
                        selected_piece = black_knight_2;
                        break;
                    case BLACK_BISHOP1:
                        printf("black bishop 1\n");
                        black_bishop_1->pick();
                        selected_piece = black_bishop_1;
                        break;
                    case BLACK_BISHOP2:
                        printf("black bishop 2\n");
                        black_bishop_2->pick();
                        selected_piece = black_bishop_2;
                        break;
                    case BLACK_QUEEN:
                        printf("black queen\n");
                        black_queen->pick();
                        selected_piece = black_queen;
                        break;
                    case BLACK_KING:
                        printf("black king\n");
                        black_king->pick();
                        selected_piece = black_king;
                        break;
                    case BLACK_PAWN1:
                        printf("black pawn 1\n");
                        black_pawn_1->pick();
                        selected_piece = black_pawn_1;
                        break;
                    case BLACK_PAWN2:
                        printf("black pawn 2\n");
                        black_pawn_2->pick();
                        selected_piece = black_pawn_2;
                        break;
                    case BLACK_PAWN3:
                        printf("black pawn 3\n");
                        black_pawn_3->pick();
                        selected_piece = black_pawn_3;
                        break;
                    case BLACK_PAWN4:
                        printf("black pawn 4\n");
                        black_pawn_4->pick();
                        selected_piece = black_pawn_4;
                        break;
                    case BLACK_PAWN5:
                        printf("black pawn 5\n");
                        black_pawn_5->pick();
                        selected_piece = black_pawn_5;
                        break;
                    case BLACK_PAWN6:
                        printf("black pawn 6\n");
                        black_pawn_6->pick();
                        selected_piece = black_pawn_6;
                        break;
                    case BLACK_PAWN7:
                        printf("black pawn 7\n");
                        black_pawn_7->pick();
                        selected_piece = black_pawn_7;
                        break;
                    case BLACK_PAWN8:
                        printf("black pawn 8\n");
                        black_pawn_8->pick();
                        selected_piece = black_pawn_8;
                        break;
                }
                break;
        }
        if(name >= 101){
            name -= 100;
            grid_row = 9-(name%8);
            switch(name%8){
                case 0:
                    printf("row = %i\n",1);
                    grid_row = 1;
                    break;
                case 7:
                    printf("row = %i\n",2);
                    break;
                case 6:
                    printf("row = %i\n",3);
                    break;
                case 5:
                    printf("row = %i\n",4);
                    break;
                case 4:
                    printf("row = %i\n",5);
                    break;
                case 3:
                    printf("row = %i\n",6);
                    break;
                case 2:
                    printf("row = %i\n",7);
                    break;
                case 1:
                    printf("row = %i\n",8);
                    break;
            }
            if(name <= 8){
                printf("column = 'A'\n");
                grid_column = 'A';
                grid_col = 1;
            }else if(name <= 16){
                printf("column = 'B'\n");
                grid_column = 'B';
                grid_col = 2;
            }else if(name <= 24){
                printf("column = 'C'\n");
                grid_column = 'C';
                grid_col = 3;
            }else if(name <= 32){
                printf("column = 'D'\n");
                grid_column = 'D';
                grid_col = 4;
            }else if(name <= 40){
                printf("column = 'E'\n");
                grid_column = 'E';
                grid_col = 5;
            }else if(name <= 48){
                printf("column = 'F'\n");
                grid_column = 'F';
                grid_col = 6;
            }else if(name <= 56){
                printf("column = 'G'\n");
                grid_column = 'G';
                grid_col = 7;
            }else if(name <= 64){
                printf("column = 'H'\n");
                grid_column = 'H';
                grid_col = 8;
            }
        }
    }
    printf("position = %c%i\n",grid_column,grid_row);
    pickPiece(grid_col,grid_row);
    checkPossibleMoves();
}

//[101][109][117][125][133][141][149][157] 8
//[102][110][118][126][134][142][150][158] 7
//[103][111][119][127][135][143][151][159] 6
//[104][112][120][128][136][144][152][160] 5
//[105][113][121][129][137][145][153][161] 4
//[106][114][122][130][138][146][154][162] 3
//[107][115][123][131][139][147][155][163] 2
//[108][116][124][132][140][148][156][164] 1
//  A    B    C    D    E    F    G    H
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
    glutInitContextVersion(2,1);
    glutCreateWindow("swag");

    glewExperimental = GL_TRUE;
    glewInit();
    initGL();
    initDLs();
    loadPieces();
    //setShaders();
    gamestate = WHITE_TURN;

    glClearColor(0.8,0.8,1,1);
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyEvents);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 1;
}
