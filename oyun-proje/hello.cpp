#include<allegro5\allegro.h>
#include "snake.h"
#include "food.h"
#define w 400
#define h 400
bool rectIntersect();
bool done = false;
snake sn(222, 200);
food  fd(111, 111);
functions func;
tail tay;
int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *que = NULL;
	ALLEGRO_TIMER *timer = NULL;
	if (!al_init())
		return -1;
	display = al_create_display(w, h);
	if (!display)
		return -1;
	al_init_primitives_addon();
	al_install_keyboard();

	que = al_create_event_queue();
	timer = al_create_timer(1. / 60.);//60fps
	
	al_register_event_source(que, al_get_timer_event_source(timer));
	al_register_event_source(que, al_get_keyboard_event_source());
	al_register_event_source(que, al_get_display_event_source(display));
	al_start_timer(timer);
	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(que, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode)
			{
					case ALLEGRO_KEY_ESCAPE:		done = true; break;
					case ALLEGRO_KEY_UP:	sn.direction(0, -2); break;
					case ALLEGRO_KEY_DOWN:	sn.direction(0,  2); break;
					case ALLEGRO_KEY_LEFT:	sn.direction(-2, 0); break;
					case ALLEGRO_KEY_RIGHT: sn.direction( 2, 0); break;
			}
		}
		printf("%d \n", sn.total);
		sn.update();
		sn.show();
		sn.make();
		sn.a += .011;
		if (rectIntersect()) {
			sn.total++;
			tay.totaly++;
			float x = rand() % 400;
			float y = rand() % 400;
			x = func.constrain(x, 50, 340);
			y = func.constrain(y, 50, 340);
			fd._x = x;
			fd._y = y;
		}
		tay.show();
		fd.show();
		al_draw_rectangle(50, 50, 350, 350, al_map_rgb(255, 255, 255), 1);//MAP
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	al_destroy_event_queue(que);
	al_destroy_display(display);
	return 0;
}
////////////////////////////////COLLISSIONNNNN/////////////////
bool rectIntersect() {
	return func.rangeIntersect(sn._x, sn._x + 20, fd._x, fd._x + 10) &&
		func.rangeIntersect(sn._y, sn._y + 20, fd._y, fd._y + 10);
}