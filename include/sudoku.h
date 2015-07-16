#define SUDOKU_SIZE 9
#define LINE_SIZE 128

typedef enum {false, true} bool;

typedef struct {
        int board[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

struct threadWrapper {
        Sudoku*  sudoku;
        bool     reverse;
        Sudoku** ans;
        int      id;
};

pthread_mutex_t g_sudoku_mutex;
pthread_cond_t  g_done;
bool            g_remainingThreadQuit;

Sudoku* copyBoard(Sudoku* su);
bool    isValid(Sudoku* su, int val, int row, int column);
void    printBoard(Sudoku* su);
Sudoku* readSudokuFromFile(const char* fileName);
bool    solve(Sudoku* su);
bool    solveAux(Sudoku* su, int row, int column, struct threadWrapper* ta);
bool    solveAuxReverse(Sudoku* su, int row, int column, struct threadWrapper* ta);
Sudoku* stringToSudoku(char* string);
char*   sudokuToString(Sudoku* su);
void*   threadRoutine(void* args);
