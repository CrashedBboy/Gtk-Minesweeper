/********************************************
File Name	:judge.c
Function 	:Tell if the game is over, 
			 and the action in the following.
Date		:2015/5/20
*********************************************/
void open_block(row, column){
	gint index;
	GtkWidget *button;

	index = row * WIDTH + column;
	if (end_flag == TRUE || map[index].marked == TRUE || map[index].opened == TRUE)
		return;

	button = map[index].button;
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button), TRUE);
	map[index].opened=TRUE;

	if (map[index].mine == TRUE){
		gtk_button_set_label(GTK_BUTTON(button), "*");
		game_end(FALSE);
		return;
	}

	if (map[index].around > 0){
		gchar buffer[2];
		g_snprintf(buffer, 2, "%d", map[index].around);
		gtk_button_set_label(GTK_BUTTON(button), buffer);
	}

	opened += 1;

	if (opened + MINE_NUM == WIDTH * HEIGHT){
		game_end(TRUE);
		return;
	}

	if (map[index].around == 0){
		if (row > 0){
			open_block(row - 1, column);
			if(column > 0) 
				open_block(row-1, column-1);
			if(column < WIDTH - 1) 
				open_block(row - 1, column + 1);
		}
		if (column > 0) 
			open_block(row, column - 1);
		if (column < WIDTH - 1) 
			open_block(row, column + 1);
		if (row < HEIGHT - 1){
			open_block(row + 1, column);
			if(column > 0) 
				open_block(row + 1, column -1);
			if(column < WIDTH - 1) 
				open_block(row + 1, column + 1);
		}
	}
}

gboolean game_end(gboolean won){
	GtkWidget *dialog;
	gchar msg[100];
	if (end_flag)
		return;
	if (won){
		g_snprintf(msg, 100, "You won! You have cleared the game in %3d seconds.", game_time);
	} else {
		g_snprintf(msg, 100, "Bad luck. Game over.");
	}
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, msg);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}