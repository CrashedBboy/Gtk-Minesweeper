/***********************************
File Name	:property.c
Function 	:Global game properties.
Date		:2015/5/20
***********************************/
static gint WIDTH = 10;
static gint HEIGHT = 10;
static gint MINE_NUM = 20;
static gint BUTTON_SIZE = 22;

static GtkWidget *remain;
static GtkWidget *during;

static gboolean game_over = FALSE;
static gint opened = 0;
static gint marked = 0;