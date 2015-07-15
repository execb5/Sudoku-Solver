#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>
#include <sudokuGUI.h>
#include <gtk/gtk.h>

GtkWidget*  g_window;
GtkWidget*  g_view;
GtkWidget*  g_button_solve;

static void
print_hello (GtkWidget *widget, gpointer data)
{
        g_print("Hello World\n");
}

GdkPixbuf*
create_pixbuf(const gchar * filename)
{
        GdkPixbuf* pixbuf;
        GError* error = NULL;
        pixbuf        = gdk_pixbuf_new_from_file(filename, &error);

        if(!pixbuf)
        {
                fprintf(stderr, "%s\n", error->message);
                g_error_free(error);
        }

        return pixbuf;
}

void
load_file_to_text_view(const char* filename)
{
        GtkTextBuffer* buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(g_view));
        GtkTextIter end;

        gtk_text_buffer_get_end_iter(buffer, &end);

        FILE* file = fopen ( filename, "r" );
        if (file != NULL)
        {
                fseek(file, 0, SEEK_END);
                long fsize = ftell(file);
                fseek(file, 0, SEEK_SET);
                char* string = malloc(fsize + 1);
                fread(string, fsize, 1, file);
                string[fsize] = 0;
                gtk_text_buffer_insert(buffer, &end, string, -1);
                fclose(file);
                free(string);
        }
        else
        {
                perror(filename); //why didn't the file open?
        }
}

Sudoku*
make_sudoku_from_text_view(void)
{
        GtkTextBuffer* buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(g_view));
        GtkTextIter start;
        GtkTextIter end;
        char* text;

        gtk_text_buffer_get_bounds(buffer, &start, &end);
        text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

        Sudoku* su = stringToSudoku(text);

        return su;
}

int
main(int argc, char* argv[])
{
        GtkBuilder* builder;
        GError*     error = NULL;

        /* Init GTK+ */
        gtk_init( &argc, &argv );

        /* Create new GtkBuilder object */
        builder = gtk_builder_new();
        /* Load UI from file. If error occurs, report it and quit application.
        * Replace "tut.glade" with your saved project. */
        if( ! gtk_builder_add_from_file( builder, "GUI/GUI.glade", &error ) )
        {
                g_warning( "%s", error->message );
                g_free( error );
                return( 1 );
        }

        /* Get main window pointer from UI */
        g_window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );
        g_view = GTK_WIDGET( gtk_builder_get_object( builder, "textview" ) );
        g_button_solve = GTK_WIDGET( gtk_builder_get_object( builder, "buttonSolve" ) );
        gtk_window_set_icon(GTK_WINDOW(g_window), create_pixbuf("img/App-Sudoku-icon.png"));
        g_signal_connect (g_button_solve, "clicked", G_CALLBACK (print_hello), NULL);

        load_file_to_text_view("examples/base");

        /* Connect signals */
        gtk_builder_connect_signals( builder, NULL );

        /* Destroy builder, since we don't need it anymore */
        g_object_unref( G_OBJECT( builder ) );

        /* Show window. All other widgets are automatically shown by GtkBuilder */
        gtk_widget_show( g_window );

        /* Start main loop */
        gtk_main();

        return( 0 );
}
