#include<stdio.h>
#include "food.h"
class tail {
	functions f;
public:
	tail() {} //constructor-def
	tail(int x, int y) { _x = x; _y = y; }
	int taily[2][100];
	int _x, _y,_ra =0;
	int totaly ;
	void sendRA(int ra) { _ra = ra; }
	void show() {
		for (int i = 0; i < totaly; i++) {
			switch (_ra) {
				case 0: 	al_draw_filled_rectangle(taily[0][i], taily[1][i] + 25, taily[0][i] + 20, taily[1][i] + 45, al_map_rgb(255, 255, 255)); break;//up
				case 1: 	al_draw_filled_rectangle(taily[0][i], taily[1][i] -5 ,  taily[0][i] + 20, taily[1][i] - 25, al_map_rgb(255, 255, 255)); break;//down
				case 2: 	al_draw_filled_rectangle(taily[0][i] + 25, taily[1][i], taily[0][i] + 45, taily[1][i] + 20, al_map_rgb(255, 255, 255)); break;//left
				case 3: 	al_draw_filled_rectangle(taily[0][i] - 5, taily[1][i], taily[0][i] - 25, taily[1][i] + 20, al_map_rgb(255, 255, 255)); break;//right
			}
		}
	}
	void update() {
		for (int i = 0; i < totaly-1; i++) {
			taily[0][i] = taily[0][i+1];
			taily[1][i] = taily[1][i + 1];
		}
		taily[0][totaly - 1] = _x;
		taily[1][totaly - 1] = _y;
	}
};