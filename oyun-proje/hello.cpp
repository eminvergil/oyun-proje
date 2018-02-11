#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "objects.h"

//GLOBALS==============================
const int w = 600;
const int h = 300;
const int num_bullets = 5;
const int num_enemy = 10;
enum keys{UP,DOWN,LEFT,RIGHT,SPACE};
bool keys[5] = { false,false, false,false,false };

//prototypes
void InitShip(SpaceShip &ship);
void DrawShip(SpaceShip &ship);
void MUP(SpaceShip &ship);
void MLEFT(SpaceShip &ship);
void MRIGHT(SpaceShip &ship);
void MDOWN(SpaceShip &ship);
//bullet
void initBull(Bullet bul[], int size);
void drawBull(Bullet bul[], int size);
void fireBull(Bullet bul[], int size,SpaceShip &ship);
void updateBull(Bullet bul[], int size);
//enemy
void initEnemy(Enemy en[], int size);
void drawEnemy(Enemy en[], int size);
void startEnemy(Enemy en[], int size);
void updateEnemy(Enemy en[], int size);
int main(void)
{
	//primitive variable
	bool done = false;
	bool redraw = true;
	const int FPS = 50;
	SpaceShip ship;
	Bullet bullets[num_bullets];
	Enemy enem[num_enemy];

	//Allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *qq = NULL;
	ALLEGRO_TIMER *t = NULL;
	//Initialization Functions
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(w , h);			//create our display object

	if (!display)										//test display object
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();

	qq = al_create_event_queue();
	t = al_create_timer(1.0 / FPS);

	srand(time(NULL));
	InitShip(ship);
	initBull(bullets, num_bullets);
	initEnemy(enem, num_enemy);

	al_register_event_source(qq, al_get_keyboard_event_source());
	al_register_event_source(qq, al_get_timer_event_source(t));
	al_register_event_source(qq, al_get_display_event_source(display));

	al_start_timer(t);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(qq, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			if (keys[UP])
				MUP(ship);
			if (keys[DOWN])
				MDOWN(ship);
			if (keys[LEFT])
				MLEFT(ship);
			if (keys[RIGHT])
				MRIGHT(ship);
			updateBull(bullets, num_bullets);
			startEnemy(enem, num_bullets);
			updateEnemy(enem, num_bullets);
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				fireBull(bullets, num_bullets, ship);
				break;

			}


		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;

			}
		}

		////
		if (redraw && al_is_event_queue_empty(qq)){
			redraw = false;
			DrawShip(ship);
			drawBull(bullets, num_bullets);
			drawEnemy(enem, num_enemy);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}
		al_destroy_display(display);						//destroy our display object

		return 0;
}

void InitShip(SpaceShip &ship)
{
	ship.x = 20;
	ship.y = h / 2;
	ship.ID = PLAYER;
	ship.lives = 3;
	ship.speed = 7;
	ship.boundx = 6;
	ship.boundy = 7;
	ship.score = 0;
}

void DrawShip(SpaceShip &ship)
{
	al_draw_filled_rectangle(ship.x, ship.y - 9, ship.x + 10, ship.y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(ship.x, ship.y + 9, ship.x + 10, ship.y + 7, al_map_rgb(255, 0, 0));

	al_draw_filled_triangle(ship.x - 12, ship.y - 17, ship.x + 12, ship.y, ship.x - 12, ship.y + 17, al_map_rgb(0, 255, 0));
	al_draw_filled_rectangle(ship.x - 12, ship.y - 2, ship.x + 15, ship.y + 2, al_map_rgb(0, 0, 255));
}

void MUP(SpaceShip & ship)
{
	ship.y -= ship.speed;
	if (ship.y < 0)
		ship.y = h;
}

void MLEFT(SpaceShip & ship)
{
	ship.x -= ship.speed;
	if (ship.x < 0)
		ship.x = w;
}

void MRIGHT(SpaceShip & ship)
{
	ship.x += ship.speed;
	if (ship.x > w)
		ship.x =0;
}

void MDOWN(SpaceShip & ship)
{
	ship.y += ship.speed;
	if (ship.y > h)
		ship.y = 0;
}
//////////////BULLETS///////////
void initBull(Bullet bul[], int size)
{
	for(int i=0;i< size ; i++)
	{
		bul[i].ID = BULLET;
		bul[i].speed = 10;
		bul[i].live = false;
	}
}

void drawBull(Bullet bul[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bul[i].live)
			al_draw_filled_circle(bul[i].x, bul[i].y, 2, al_map_rgb(255, 255, 255));
	}
}

void fireBull(Bullet bul[], int size, SpaceShip &ship)
{
	for (int i = 0; i < size; i++)
	{
		if (!bul[i].live) {
			bul[i].x = ship.x + 15;
			bul[i].y = ship.y ;
			bul[i].live = true;
			break;
		}
	}
}

void updateBull(Bullet bul[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bul[i].live) {
			bul[i].x += bul[i].speed;
			if (bul[i].x > w)
				bul[i].live = false;
		}
	}
}
////////////ENEMY
void initEnemy(Enemy en[], int size)
{
	for (int i = 0; i < size; i++)
	{
		en[i].ID = ENEMY;
		en[i].live = false;
		en[i].speed = 5;
		en[i].boundx = 19;
		en[i].boundy = 19;
	}
}

void drawEnemy(Enemy en[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (en[i].live) {
			al_draw_filled_circle(en[i].x, en[i].y, 20, al_map_rgb(255, 0, 0));
		}
	}
}

void startEnemy(Enemy en[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!en[i].live) {
			if (rand() % 500 == 0) 
			{
				en[i].live = true;
				en[i].x = w;
				en[i].y = 30 + rand() % (h - 60);
				break;
			}
		}
	}
}

void updateEnemy(Enemy en[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (en[i].live) {
			en[i].x -= en[i].speed;
			if (en[i].x < 0)
				en[i].live = false;
		}
	}
}
