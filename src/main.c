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

void
load_msg(GtkWidget *widget, gpointer window)
{
        printf("Load selected\n");
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
                
                GtkWidget* window;
                GtkWidget* vbox;
                GtkWidget* halign;
                
                GtkWidget* button;
                GtkWidget* menubar;
                GtkWidget* fileMenu;
                GtkWidget* fileMi;
                GtkWidget* openMi;
                GtkWidget* sep;
                GtkWidget* quitMi;
                
                gtk_init(&argc, &argv);
                
                window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
                gtk_window_set_title(GTK_WINDOW(window), "Sudoku Solver");
                gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
                gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
                gtk_container_set_border_width(GTK_CONTAINER(window), 15);
                
                vbox = gtk_vbox_new(FALSE, 0);
                halign = gtk_alignment_new(0, 0, 0, 0);
                gtk_container_add(GTK_CONTAINER(window), vbox);
                
                menubar = gtk_menu_bar_new();
                
                fileMenu = gtk_menu_new();
                fileMi   = gtk_menu_item_new_with_mnemonic("_File");
                openMi   = gtk_menu_item_new_with_mnemonic("_Open");
                sep      = gtk_separator_menu_item_new();
                quitMi   = gtk_menu_item_new_with_mnemonic("_Quit");
                
                gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
                gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
                gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), sep);
                gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
                gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
                
                button = gtk_button_new_with_mnemonic("_Solve");
                
                gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
                gtk_container_add(GTK_CONTAINER(halign), button);
                gtk_container_add(GTK_CONTAINER(vbox), halign);
                
                g_signal_connect(button, "clicked",
                                G_CALLBACK(print_msg), NULL);
                
                g_signal_connect(G_OBJECT(quitMi), "activate",
                                  G_CALLBACK(gtk_main_quit), NULL);
                
                g_signal_connect(G_OBJECT(openMi), "activate",
                                  G_CALLBACK(load_msg), NULL);
                
                g_signal_connect_swapped(G_OBJECT(window), "destroy",
                                G_CALLBACK(gtk_main_quit), NULL);
                
                gtk_widget_show_all(window);
                
                gtk_main();
        }
        return 0;
}
