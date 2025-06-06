#ifndef PLAYERH
#define PLAYERH

class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	void removeLife();
	bool isGameOver(){ return gameOver; }
	// Needed for lives UI
	int getLives(){ return lives; }
private:
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
	ALLEGRO_BITMAP *image;
	// The sprites when kirby is damaged
	ALLEGRO_BITMAP *life_sprites[4] = {
		al_load_bitmap("Kirby1.png"),
		al_load_bitmap("Kirby2.png"),
		al_load_bitmap("Kirby3.png"),
		al_load_bitmap("Kirby4.png")
	};
	// Update by 1 when life is lost and use it to find sprite index
	int loseCounter = -1;
	// Value for gameover
	bool gameOver = false;
};
#endif
