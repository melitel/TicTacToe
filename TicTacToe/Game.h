#pragma once
#include "Board.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
	void run();

private:
	void gather_input();
	void draw();
	void update();
	void initialize();
	void initialize_sfml();
	uint32_t get_index_by_mouse_position(const sf::Vector2i &mouse_position);

	enum class player {cross, circle};	
	player m_player{player::cross};
	Board m_board;
	Board::state m_game_state;
	struct Cell {
		sf::RectangleShape rect;
		sf::Text text;
	};
	bool m_success_move{false};

	//SFML graphics objects
	sf::RenderWindow m_window{ sf::VideoMode(265, 350), "My window" };
	std::array<Game::Cell, 9> m_cells;
	sf::Text m_result_text;
	sf::Font m_font;
	const float rect_offset{ 10 };
	const float text_offset_side{ 20 };
	const float text_offset_top{ 10 };
	const float cell_size{ 75 };
	const sf::Color cell_color{ 255, 255, 255 };
};

