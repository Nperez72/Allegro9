#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	al_destroy_bitmap(image);
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
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if(y > HEIGHT)
		y = HEIGHT;
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
// Use screen dimensions to determine when player hits the edges of the screen
// Reset position if true
void player::handle_bounds(int screen_w, int screen_h) {
    int pw = al_get_bitmap_width(image);
    int ph = al_get_bitmap_height(image);
    bool flipped = false;

    if (x < 0) {
        x = 0;
    }
    if (x > screen_w - pw) {
        x = screen_w - pw;
    }
    if (y < 0) {
        y = 0;
    }
    if (y > screen_h - ph) {
        y = screen_h - ph;

    }

}
