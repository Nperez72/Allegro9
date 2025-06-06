#include "player.h"
#include "ghost.h"

class Arrow
{
public:
	Arrow();
	~Arrow();
	void DrawArrow();
	void FireArrow(player &Player);
	void UpdateArrow(int WIDTH);
	void CollideArrow(ghost ghosts[], int cSize);
	static int getScore(){ return score; }
private:
	int x;
	int y;
	bool live;
	int speed;
	// Score for hitting enemies, + 1 for each enemy hit
	static int score;
	ALLEGRO_BITMAP *image;
};

