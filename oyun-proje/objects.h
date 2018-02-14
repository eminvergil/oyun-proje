#include<allegro5\allegro.h>

class snake {
private:
	int x, y, xspeed, yspeed;
public :
	snake(int _x,int _y, int _xspeed, int _yspeed) {
		x = _x;
		y = _y;
		xspeed = _xspeed;
		yspeed = _yspeed;
	}

	void update() {
		x += xspeed;
		y += yspeed;
		if (x < 0) x = 0;
		else if (y < 0) y = 0;
		else if (x >= 600) x = 600;
		else if (y >= 600) y = 600;
	}
	void dir(int _x, int _y) {
		xspeed = _x*5;
		yspeed = _y*5;
	}
	void show() {
		al_draw_filled_rectangle(x, y - 20, x + 20, y - 40, al_map_rgb(111,10,222));
	}
};