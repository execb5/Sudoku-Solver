#define SUDOKU_SIZE 9
#define LINE_SIZE 128

typedef enum {false, true} bool;

typedef struct {
        int board[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

Sudoku* copyBoard(Sudoku* su);
bool isValid(Sudoku* su, int val, int row, int column);
void printBoard(Sudoku* su);
Sudoku* readSudokuFromFile(const char* fileName);
bool solve(Sudoku* su);
bool solveAux(Sudoku* su, int row, int column);
Sudoku* stringToSudoku(char* string);
char* sudokuToString(Sudoku* su);
