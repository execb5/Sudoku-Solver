#include <gtk/gtk.h>

extern GtkWidget* g_window;
extern GtkWidget* g_view;
extern GtkWidget* g_button_solve;
extern GtkWidget* g_button_open;
extern Sudoku*    g_sudoku;

GdkPixbuf* create_pixbuf(const gchar * filename);
void load_file_to_text_view(const char* filename);
void load_sudoku_to_text_view(Sudoku* su);
Sudoku* make_sudoku_from_text_view(void);
void open_sudoku(void);
void solve_sudoku(void);
