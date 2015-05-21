/***********************************
File Name	:event.c
Function 	:Event handler
Date		:2015/5/20
***********************************/
gboolean on_mouse_click (GtkWidget *widget, GdkEventButton *event, gpointer data){
	gint index, row, column;
	gchar buffer[4];

	if(game_over == TRUE)
		return TRUE;
	index = (gint)data;

	switch(event->button){
		case 1:
			row = index / WIDTH;
			column = index % WIDTH;
			//open_block(row, column);
			break;
		case 2:
			break;
		case 3:
			if (map[index].opened == TRUE)
				break;
			if (map[index].marked != TRUE){
				map[index].marked = TRUE;
				gtk_button_set_label(GTK_BUTTON(widget), "@");
				marked += 1;
			}else {
				map[index].marked = FALSE;
				gtk_button_set_label(GTK_BUTTON(widget), "");
				marked -= 1;
			}
			g_snprintf(buffer, 4, "%d", MAX(0, MINE_NUM-marked));
			gtk_label_set_text(GTK_LABEL(remain), buffer);
	}
	return TRUE;
}

