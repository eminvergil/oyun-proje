#include<allegro5\allegro_primitives.h>
#include "functions.h"
class food {
	functions f;
public:
	float _x, _y;
	food(float x,float y) {
		_x = x;
		_y = y;
		_x = f.constrain(_x, 50, 330);
		_y = f.constrain(_y, 50, 330);
	}
	void show() {
		al_draw_rectangle(_x, _y, _x+10,_y+10, al_map_rgb(222, 0, 0), 1);
	}
};