#pragma once

#include "stdIncludes.h"
#include "state.h"

int random_number (int min, int max);

enum PieceTypes { I, J, L, O, S, T, Z };
enum CellColor { YellowCell, PurpleCell, RedCell, GreenCell, BlueCell };
struct Cell {
	bool isOccupied;
	int color;
};

enum GameState {
	MainMenu,
	Playing,
	Paused,
	GameOver,
	HowTo,
	OptionsMenu,
	Credits
};

class Tetris
{
public:
	static Tetris *GetInstance();
	void ChangeState(int newState);

	void CreateAllegroDisplay();
	void LoadFonts();
	void Initialize();
	void TrackMouse();
	void StartTetris();
	void Terminate();

	void setDoneState(bool newState) { done = newState; }

	ALLEGRO_DISPLAY * GetDisplay() { return display; }
	ALLEGRO_TIMER * GetTimer() { return timer; }
	ALLEGRO_TIMER * GetGravityTimer() { return gravityTimer; }
	ALLEGRO_TIMER * GetSoftDropTimer() { return softDropTimer; }
	ALLEGRO_TIMER * GetSidewaysMovementTimer() { return sidewaysMovementTimer; }
	ALLEGRO_FONT *font;

	double mouse_x, mouse_y;
	bool left_mouse_button_pressed;
	bool left_mouse_button_released;

private:
	static Tetris *instance;
	int state;
	vector<State*> states;

	ALLEGRO_BITMAP *mouse;

	bool done, draw;

	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_TIMER *gravityTimer;
	ALLEGRO_TIMER *softDropTimer;
	ALLEGRO_TIMER *sidewaysMovementTimer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_EVENT ev;
};