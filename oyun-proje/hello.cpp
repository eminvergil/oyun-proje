#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include<stdio.h>
#include "objects.h"

//GLOBALS==============================
const int w = 600;
const int h = 600;

snake sn(200,200,1,1);
int main(void) 
{
	bool done = false;
	bool draw = true;
	////allegro things//////
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
	timer = al_create_timer(1./60);

	al_register_event_source(que, al_get_keyboard_event_source());
	al_register_event_source(que, al_get_timer_event_source(timer));
	al_register_event_source(que, al_get_display_event_source(display));
	/////////
	al_start_timer(timer);
	while (!done) 
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(que, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			//printf("BLABLA");
			draw = true;
			sn.show();
			sn.update();
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					sn.dir(0, -1);
					break;
				case ALLEGRO_KEY_DOWN:
					sn.dir(0, 1);
					break;
				case ALLEGRO_KEY_RIGHT:
					sn.dir(1, 0);
					break;
				case ALLEGRO_KEY_LEFT:
					sn.dir(-1, 0);
					break;
			}
		}

		if (draw && al_is_event_queue_empty(que)) {
			draw = false;
			sn.show();
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	return 0;
}