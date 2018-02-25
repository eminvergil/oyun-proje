#include<stdio.h>
class tail {
public:
	int tailX[100], tailY[100];
	int _x, _y;
	int totaly = 0;
	void show() {
		for (int i = 0; i < totaly - 1; i++) {
			al_draw_rectangle(tailX[i], tailY[i], tailX[i] + 20, tailY[i] + 20, al_map_rgb(0, 0, 222), 1);
		}
	}
	void update() {
		printf("%d totalyy", totaly);
		for (int i = 0; i < totaly - 1; i++) {
			tailX[i] = tailX[i + 1];
			tailY[i] = tailY[i + 1];
		}
		tailX[totaly -1] = _x;
		tailX[totaly -1] = _y;
	}
	tail(){} //constructor-def
	tail(int x, int y) { _x = x; _y = y; }
};