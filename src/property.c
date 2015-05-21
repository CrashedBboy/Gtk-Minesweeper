/***********************************
File Name	:property.c
Function 	:Global game properties.
Date		:2015/5/20
***********************************/
static gint WIDTH = 10;
static gint HEIGHT = 10;
static gint MINE_NUM = 5;
static gint BUTTON_SIZE = 22;

static GtkWidget *remain;
static GtkWidget *during;

static gboolean end_flag = FALSE;
static gint opened = 0;
static gint marked = 0;

static gint game_time = 0;

void mine_init();
void mine_set();
void update_around(gint);

void layout_init();
void set_labels();
void fill_map();

gboolean on_mouse_click(GtkWidget*, GdkEventButton*, gpointer);

void open_block(gint, gint);
gboolean game_end(gboolean);

gboolean tick(gpointer);