#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sudoku.h>
#include <gtk/gtk.h>

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

int
main(int argc, char* argv[])
{
        GtkBuilder *builder;
        GtkWidget  *window;
        GtkWidget  *view;
        GError     *error = NULL;

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
        window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );
        view = GTK_WIDGET( gtk_builder_get_object( builder, "textview" ) );
        gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("img/App-Sudoku-icon.png"));

        GtkTextBuffer* buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
        GtkTextIter end;

        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_buffer_insert(buffer, &end, "Hello ubuntuforums", -1);

        /* Connect signals */
        gtk_builder_connect_signals( builder, NULL );

        /* Destroy builder, since we don't need it anymore */
        g_object_unref( G_OBJECT( builder ) );

        /* Show window. All other widgets are automatically shown by GtkBuilder */
        gtk_widget_show( window );

        /* Start main loop */
        gtk_main();

        return( 0 );
}
