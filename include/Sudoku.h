#define SUDOKU_SIZE 9

typedef enum {false, true} bool;

typedef struct {
        int board[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

bool is1stQOk(Sudoku* su);
bool is2ndQOk(Sudoku* su);
bool is3rdQOk(Sudoku* su);
bool is4thQOk(Sudoku* su);
bool is5thQOk(Sudoku* su);
bool is6thQOk(Sudoku* su);
bool is7thQOk(Sudoku* su);
bool is8thQOk(Sudoku* su);
bool is9thQOk(Sudoku* su);
bool isBoardCorrect(Sudoku* su);
bool isColumnCorrect(Sudoku* su, int line);
bool isLineCorrect(Sudoku* su, int line);
void readSudokuFromFile(char* fileName, Sudoku* su);
void solve(Sudoku* su);
void printBoard(Sudoku* su);
