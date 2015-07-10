#define SUDOKU_SIZE 9
#define LINE_SIZE 128
#define FIRST_SECTION 3
#define SECOND_SECTION 6

typedef enum {false, true} bool;

typedef struct {
        int board[SUDOKU_SIZE][SUDOKU_SIZE];
} Sudoku;

extern int checker[SUDOKU_SIZE];

bool checkChecker(void);
Sudoku* copyBoard(Sudoku* su);
bool freePos(Sudoku* su, int y, int x);
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
bool isColumnCorrect(Sudoku* su, int column);
bool isLineCorrect(Sudoku* su, int line);
bool isValid(Sudoku* su, int val, int row, int column);
void printBoard(Sudoku* su);
Sudoku* readSudokuFromFile(const char* fileName);
void resetChecker(void);
bool solve(Sudoku* su);
bool solveAux(Sudoku* su, int row, int column);
bool write(Sudoku* su, int val, int row, int column);
