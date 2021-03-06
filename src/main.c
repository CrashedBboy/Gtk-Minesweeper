#include <stdio.h>
#include <gtk/gtk.h>
#include "property.c"
#include "mine.c"
#include "layout.c"
#include "event.c"
#include "clock.c"
#include "judge.c" 

int main(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	mine_init();
	layout_init();
	g_timeout_add(1000, (GSourceFunc)tick, NULL);
	gtk_main();
	return 0;
}