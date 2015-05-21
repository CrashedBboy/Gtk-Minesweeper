/***********************************
File Name	:clock.c
Function 	:Time counter
Date		:2015/5/20
***********************************/

gboolean tick(gpointer data){
	gchar buf[8];
	if(end_flag==TRUE)
		return FALSE;
	game_time++;
	g_snprintf(buf, 8, "%d", game_time);
	gtk_label_set_text(GTK_LABEL(during), buf);
	return TRUE;
}