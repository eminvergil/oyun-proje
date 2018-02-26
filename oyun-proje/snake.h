#include<allegro5\allegro_primitives.h>
#include<math.h>
#include "tail.h"
class snake {
	tail tay;
public:
	int _x,_y, _xspeed = 1,_yspeed = 0,total = 0;
	float a = .1;
	int _ra;
	snake(){}//default constructor
	snake(int x,int y) {
		_x = x;
		_y = y;
		_x = constrain(_x, 50, 330);
		_y = constrain(_y, 50, 330);
	}
	void takeRA(int ra) {
		_ra = ra;
	}
	void direction(int x, int y) {
		_xspeed = x;
		_yspeed = y;
	}
	void update() {
		_x += _xspeed*2;
		_y += _yspeed*2;
		switch (_ra) {
			case 0:tay._ra = _ra; break;
			case 1:tay._ra = _ra; break;
			case 2:tay._ra = _ra; break;
			case 3:tay._ra = _ra; break;
		}
		tay._x = _x;
		tay._y = _y;
		tay.totaly = total;
		tay.update();
		_x = constrain(_x, 50, 330);
		_y = constrain(_y, 50, 330);
		//printf("%d :_x , %d : _y \n", _x,_y);
	}
	void show() {
		al_draw_filled_rectangle(_x, _y, _x + 20, _y + 20, al_map_rgb(0, 0, 220));
		tay.show();
	}
	float map(float value,float start1,float stop1, float start2, float stop2) {
		float outgoing = 
			start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
		return outgoing;
	}
	float constrain(float amt, float low, float high) {
		return (amt < low) ? low : ((amt > high) ? high : amt);
	}
	void make() {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				float x = map(sin(a + i), -1, 1, 50, 344);
				float y = map(cos(a + j), -1, 1, 50, 344);
				al_draw_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 66, 0), 1.4);
			}
		}
	}
};
