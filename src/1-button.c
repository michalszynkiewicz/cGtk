#include <gtk/gtk.h>

void button_clicked(GtkWidget *widget, gpointer data) {
    printf("clicked\n");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *win;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win), "Button example");

    // button:
    button = gtk_button_new_with_label("Click");
    gtk_container_add(GTK_CONTAINER(win), button);
    gtk_widget_set_size_request(button, 80, 35);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), NULL);


    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);
    gtk_main();

    return 0;
}
