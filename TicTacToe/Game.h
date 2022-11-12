#pragma once
#include "Board.h"

class Game
{
public:
	void run();

private:
	void gather_input();
	void draw();
	void update();
	void initialize();

	enum class player {cross, circle};	
	player m_player{player::cross};
	Board m_board;
	Board::state m_game_state;
};

