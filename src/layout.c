/****************************************
File Name	:layout.c
Function 	:Layout and mine distribution
Date		:2015/5/20
****************************************/
static GtkWidget *remain;
static GtkWidget *during;
GtkWidget *main_container;

void main_container_init(){
	main_container = gtk_vbox_new(FALSE, 0);
	set_labels();
}

void set_labels(){
	GtkWidget *hbox;
	GtkWidget *label;
	hbox = gtk_hbox_new(FALSE, 0);
	
	label= gtk_label_new("Mines:");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 4);

	remain = gtk_label_new("0");
	gtk_box_pack_start(GTK_BOX(hbox), remain, FALSE, FALSE, 2);

	label= gtk_label_new("Time:");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 4);

	during = gtk_label_new("0");
	gtk_box_pack_start(GTK_BOX(hbox), during, FALSE, FALSE, 2);

	gtk_box_pack_start(GTK_BOX(main_container), hbox, FALSE, FALSE, 0);
	gtk_widget_show_all(hbox);
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
			gtk_widget_show(button);
			//g_signal_connect(G_OBJECT(button),"button-press-event",G_CALLBACK(on_mouse_click),(gpointer)index);
			map[index].button = button;
			index++;
		}
		gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
		gtk_widget_show(hbox);
	}















}