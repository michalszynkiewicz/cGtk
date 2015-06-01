#include <gtk/gtk.h>


/*** Obsluga zdarzenia rysowania */
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 1);
    cairo_move_to(cr, 100, 100);
    cairo_line_to(cr, 200, 200);
    cairo_stroke(cr);
    return FALSE;
}


int main(int argc, char *argv[]) {
    /*** Niezbedne widgety ***/
    GtkWidget *win = NULL;
    GtkWidget *darea = NULL;

    /*** Inicjalizacja GTK+ ***/
    gtk_init(&argc, &argv);

    /*** Utworzenie okna ***/
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_fullscreen(GTK_WINDOW(win));

    /*** Obszar, po ktorym bedziemy rysowac */
    darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(win), darea);

    /*** Ustawienie obslugi zdarzen */
    g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /*** Glowna petla programu ***/
    gtk_widget_show_all(win);
    gtk_main();

    return 0;
}
