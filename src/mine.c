/***********************************
File Name	:mine.c
Function 	:Define struct of mine
Date		:2015/5/20
***********************************/
struct block{
	gint around;
	gboolean mine;
	gboolean marked;
	gboolean opened;
	GtkWidget *button; 
};

static struct block *map;
void mine_set();
void update_around();

void mine_init(){
	map = (struct block *)g_malloc0(sizeof(struct block)* WIDTH * HEIGHT);
	mine_set();
}

void mine_set(){
	gint size = WIDTH * HEIGHT;
	gint i = 0;
	while (i < MINE_NUM){
		gint index, row, column;
		index = g_random_int_range(0, size);
		if (map[index].mine == TRUE)
			continue;
		map[index].mine = TRUE;
		update_around(index);
		i += 1;
	}
}

void update_around(gint index){
	gint row, column;
	row = index / WIDTH;
	column = index % WIDTH;
	if (row > 0){
			map[index - WIDTH].around += 1;
			if (column > 0)
				map[index - WIDTH - 1].around += 1;
			if (column < WIDTH-1)
				map[index - WIDTH + 1].around += 1;
		}
		if (row < HEIGHT-1){
			map[index + WIDTH].around += 1;
			if (column > 0)
				map[index + WIDTH - 1].around += 1;
			if (column < WIDTH-1)
				map[index + WIDTH + 1].around += 1;
		}
		if (column > 0)
			map[index-1].around += 1;
		if (column < WIDTH-1)
			map[index+1].around += 1;
}