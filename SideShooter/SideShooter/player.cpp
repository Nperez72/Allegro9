#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	al_destroy_bitmap(image);
	// Clean up sprite array
	delete[] life_sprites;
}
player::player(int HEIGHT)
{

	image = al_load_bitmap("Kirby.png");
	x = 20;
	y = HEIGHT / 2;
	lives = 5;
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;
}
void player::DrawPlayer()
{
	al_draw_bitmap(image, x,y, 0);
}
void player::MoveUp()
{
	y -= speed;
	if(y < 0)
		y = 0;
}
// Move down will now properly handle collison at the bottom of the screen
void player::MoveDown(int HEIGHT)
{
	int ph = al_get_bitmap_height(image);
	y += speed;
	if(y > HEIGHT - ph)
		y = HEIGHT - ph;
}
void player::MoveLeft()
{
	x -= speed;
	if(x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if(x > 300)
		x = 300;
}
