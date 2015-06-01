#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkWidget *win;

    gtk_init(&argc, &argv);

    /* Utworzenie okna ***/
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* obsługa zamknięcia okna: */
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show(win);
    gtk_main();

    return 0;
}
