/****************************************
File Name	:layout.c
Function 	:Layout and mine distribution
Date		:2015/5/20
****************************************/
GtkWidget *window;
GtkWidget *base_container;
GtkWidget *content_container;

void layout_init(){
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Minesweeper");
	gtk_window_set_default_size(GTK_WINDOW(window), BUTTON_SIZE*WIDTH, BUTTON_SIZE*HEIGHT + 20);
	g_signal_connect(G_OBJECT(window), "delete_event",gtk_main_quit, NULL);

	base_container = gtk_vbox_new(FALSE, 0);
	content_container = gtk_vbox_new(FALSE, 0);

	set_labels();
	fill_map();

	gtk_box_pack_start(GTK_BOX(base_container), content_container, TRUE, TRUE, 10);
	gtk_container_add(GTK_CONTAINER(window), base_container);
	gtk_widget_show_all(window);
}

void set_labels(){
	GtkWidget *hbox;
	GtkWidget *label;
	gchar buffer[4];
	hbox = gtk_hbox_new(FALSE, 0);
	
	label= gtk_label_new("Mines:");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 4);
	
	g_snprintf(buffer, 4, "%d", MAX(0, MINE_NUM-marked));
	remain = gtk_label_new(buffer);
	gtk_box_pack_start(GTK_BOX(hbox), remain, FALSE, FALSE, 2);

	label= gtk_label_new("Time:");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 4);

	during = gtk_label_new("0");
	gtk_box_pack_start(GTK_BOX(hbox), during, FALSE, FALSE, 2);

	gtk_box_pack_start(GTK_BOX(content_container), hbox, FALSE, FALSE, 5);
}

void fill_map(){
	gint i, j, index = 0;
	GtkWidget *hbox;
	hbox = gtk_hbox_new(FALSE, 0);

	for(i = 0; i < HEIGHT; i++){
		hbox = gtk_hbox_new(FALSE, 0);
		for (j = 0; j < WIDTH; j++){
			GtkWidget *button;
			button = gtk_button_new();
			gtk_widget_set_size_request(button, BUTTON_SIZE, BUTTON_SIZE);
			g_object_set(G_OBJECT(button), "can-focus", FALSE, NULL);
			gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 0);
			g_signal_connect(G_OBJECT(button),"button-press-event",G_CALLBACK(on_mouse_click),(gpointer)index);
			map[index].button = button;
			index++;
		}
		gtk_box_pack_start(GTK_BOX(content_container), hbox, FALSE, FALSE, 0);
	}
}