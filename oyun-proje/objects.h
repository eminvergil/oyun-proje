#include<allegro5\allegro.h>
#include "tail.h"
class snake {
private:
	int x, y, xspeed, yspeed;
	
public :
	int total = 1;
	Tail tail[13];
	
	

	snake(int _x, int _y, int _xspeed, int _yspeed) {
		x = _x;
		y = _y;
		xspeed = _xspeed;
		yspeed = _yspeed;
		tail[0].x = x;
		tail[0].y = y;
	}

	void update() {
		
			printf("%d \n",total);
			for (int i = 0; i < total-1; i++) {
				tail[i] = tail[i + 1];
			}
		
		tail[total -1].x = x;
		tail[total -1].y = y;

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
		for (int i = 0; i < total-1; i++) {
			al_draw_filled_rectangle(tail[i].x+2, tail[i].y - 22, tail[i].x + 22, tail[i].y - 42, al_map_rgb(111, 10, 111));
		}
		al_draw_filled_rectangle(x, y - 20, x + 20, y - 40, al_map_rgb(111,10,222));
	}
};