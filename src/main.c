#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sudoku.h>
#include <gtk/gtk.h>

void
print_msg(GtkWidget *widget, gpointer window)
{

        printf("Button clicked\n");
}

int
main(int argc, char* argv[])
{
        if (argc > 1)
        {
                int i;
                time_t start;
                time_t stop;
                Sudoku* su;
                for (i = 1; i < argc; i++)
                {
                        printf("%s\n", argv[i]);
                        su = readSudokuFromFile(argv[i]);
                        printBoard(su);
                        time(&start);
                        solve(su);
                        time(&stop);
                        printBoard(su);
                        free(su);
                        printf("Solved in %.0fs", difftime(stop, start));
                        printf("\n");
                        printf("-------------------------------------------\n");
                        printf("-------------------------------------------\n");
                }
        }
        else
        {
                printf("COMMAND LINE USAGE:\n");
                printf("./sudoku <SUDOKU_FILE> <SUDOKU_FILE>...\n");
                
                GtkWidget *window;
                GtkWidget *button;
                GtkWidget *halign;
                
                gtk_init(&argc, &argv);
                
                window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
                gtk_window_set_title(GTK_WINDOW(window), "Mnemonic");
                gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
                gtk_container_set_border_width(GTK_CONTAINER(window), 15);
                
                button = gtk_button_new_with_mnemonic("_Button");
                
                g_signal_connect(button, "clicked",
                                G_CALLBACK(print_msg), NULL);
                
                halign = gtk_alignment_new(0, 0, 0, 0);
                gtk_container_add(GTK_CONTAINER(halign), button);
                gtk_container_add(GTK_CONTAINER(window), halign);
                
                gtk_widget_show_all(window);
                
                g_signal_connect_swapped(G_OBJECT(window), "destroy",
                                G_CALLBACK(gtk_main_quit), NULL);
                
                gtk_main();
        }
        return 0;
}
