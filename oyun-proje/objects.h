#include<allegro5\allegro.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "tail.h"
class snake {
public:
	int x, y, xspeed, yspeed;
	int x1, y1;
	int total = 1;
	Tail tail[100];
	
	snake(int _x, int _y, int _xspeed, int _yspeed) {
		x = _x;
		y = _y;
		xspeed = _xspeed;
		yspeed = _yspeed;	
		x1 = x;
		y1 = y;
	}

	void update() {
		srand(time(NULL));
			printf("%d \n",total);
			for (int i = 0; i < total-1; i++) {
				tail[i] = tail[i + 1];
			}


		x += xspeed;
		y += yspeed;
		if (x < 60) x = 60;
		else if (y < 60) y = 60;
		else if (x >= 540) x = 540;
		else if (y >= 541) y = 540;
		x1 = x;
		y1 = y;
		tail[total - 1].x = x1;
		tail[total - 1].y = y1;

	}
	void dir(int _x, int _y) {
		xspeed = _x;
		yspeed = _y;
	}
	void show() {
		for (int i = 0; i < total-1; i++) {
			al_draw_filled_rectangle(tail[i].x+21, tail[i].y  , tail[i].x +41, tail[i].y + 20, al_map_rgb(111, 10, 111));
		}
		///MAP//////
		al_draw_rectangle(50, 50, 550, 550, al_map_rgb(255, 255, 255), 2);
		al_draw_filled_rectangle(x  , y  , x + 20, y + 20, al_map_rgb(111,10,222));
	}
};