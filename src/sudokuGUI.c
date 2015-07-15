#include <stdio.h>
#include <stdlib.h>
#include <sudoku.h>
#include <sudokuGUI.h>
#include <gtk/gtk.h>

GtkWidget* g_window;
GtkWidget* g_view;
GtkWidget* g_button_solve;
Sudoku*    g_sudoku;

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

        FILE* file = fopen ( filename, "r" );
        if (file != NULL)
        {
                fseek(file, 0, SEEK_END);
                long fsize = ftell(file);
                fseek(file, 0, SEEK_SET);
                char* string = malloc(fsize + 1);
                fread(string, fsize, 1, file);
                string[fsize] = 0;
                gtk_text_buffer_set_text(buffer, string, -1);
                fclose(file);
                free(string);
        }
        else
        {
                perror(filename); //why didn't the file open?
        }
}

void
load_sudoku_to_text_view(Sudoku* su)
{
        GtkTextBuffer* buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(g_view));

        gtk_text_buffer_set_text(buffer, sudokuToString(su), -1);
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

void
solve_sudoku(void)
{
        g_sudoku = make_sudoku_from_text_view();
        solve(g_sudoku);
        load_sudoku_to_text_view(g_sudoku);
        free(g_sudoku);
}

int
main(int argc, char* argv[])
{
        GtkBuilder* builder;
        GError*     error = NULL;

        gtk_init( &argc, &argv );

        builder = gtk_builder_new();

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

        g_signal_connect(g_button_solve, "clicked", G_CALLBACK(solve_sudoku), NULL);

        //Put something on the textview
        load_file_to_text_view("examples/base");

        /* Connect signals */
        gtk_builder_connect_signals( builder, NULL );

        /* Destroy builder, since we don't need it anymore */
        g_object_unref( G_OBJECT( builder ) );

        gtk_widget_show( g_window );

        gtk_main();

        return( 0 );
}
