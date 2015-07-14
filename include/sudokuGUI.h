#include <gtk/gtk.h>

extern GtkWidget*  g_window;
extern GtkWidget*  g_view;
extern GtkWidget*  g_button_solve;

GdkPixbuf* create_pixbuf(const gchar * filename);
void load_file_to_text_view(const char* filename);
