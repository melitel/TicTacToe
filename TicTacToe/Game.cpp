#include "Game.h"
#include <iostream>
#include <string>

const uint32_t INVALID_INDEX = uint32_t(-1);

bool isNumber(std::string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0)
			return false;
	}
	return true;
}

void Game::run()
{
	initialize();

	while (m_window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		gather_input();
		update();
		draw();
	}
}

void Game::gather_input()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_game_state == Board::state::ingame)
	{
		// get the local mouse position (relative to a window)
		sf::Vector2i mouse_position = sf::Mouse::getPosition(m_window); // window is a sf::Window
		uint32_t index = get_index_by_mouse_position(mouse_position);

		if (index != INVALID_INDEX)
		{
			m_success_move = m_board.make_move(index, (m_player == player::circle ? 'O' : 'X'));
		}
	}
}

void Game::draw()
{
	// clear the window with black color
	m_window.clear(sf::Color::Black);

	for (int i = 0; i < m_cells.size(); i++)
	{
		m_window.draw(m_cells[i].rect);
		m_window.draw(m_cells[i].text);
	}

	m_window.draw(m_result_text);
	// end the current frame
	m_window.display();
	
}

void Game::update()
{
	m_game_state = m_board.update_state();

	//show only non digits
	for (uint32_t i = 0; i < m_cells.size(); i++)
	{
		if (m_board.get_value_by_index(i) != '.') {
			m_cells[i].text.setString(m_board.get_value_by_index(i));		
		}
	}

	if (m_game_state == Board::state::draw)
	{
		m_result_text.setString("It's a draw");
	}
	else if (m_game_state == Board::state::win)
	{
		std::vector<int> win_combo = m_board.get_win_combo();
		for (int id : win_combo) {
			m_cells[id].rect.setFillColor(sf::Color::Green);
		}
		m_result_text.setString(std::string(m_player == player::circle ? "O" : "X") + " Wins");
	}
	else
	{
		m_result_text.setString(std::string(m_player == player::circle ? "O" : "X") + " make a move");
	}

	if (m_game_state == Board::state::ingame && m_success_move)
	{
		if (m_player == player::circle)
		{
			m_player = player::cross;
		}
		else {
			m_player = player::circle;
		}

		m_success_move = false;
	}	
}

void Game::initialize()
{
	m_game_state = Board::state::ingame;
	
	m_board.initialize();
	initialize_sfml();	
}



void Game::initialize_sfml()
{
	if (!m_font.loadFromFile("arial.ttf"))
	{
		int ii = 10;
	}

	for (int i = 0; i < 3; i++) {
	
		const float offset_rect_i = rect_offset + (cell_size + rect_offset)*i;
		const float offset_text_i = offset_rect_i + text_offset_side;

		for (int j = 0; j < 3; j++)
		{
			const int cell_index = i + j * 3;
			const float offset_rect_j = rect_offset + (cell_size + rect_offset) * j;
			const float offset_text_j = offset_rect_j + text_offset_top;

			Cell& cell = m_cells[cell_index];
			cell.rect.setSize(sf::Vector2f(cell_size, cell_size));
			cell.rect.setFillColor(cell_color);
			cell.rect.setPosition(sf::Vector2f(offset_rect_i, offset_rect_j));

			//text
			cell.text.setFont(m_font); // font is a sf::Font
			cell.text.setCharacterSize(45);
			// set the color
			cell.text.setFillColor(sf::Color::Black);

			// set the text style
			cell.text.setStyle(sf::Text::Bold);
			cell.text.setPosition(sf::Vector2f(offset_text_i, offset_text_j));
			
			//char value;

			//if (m_board.get_value_by_index(cell_index, &value)){
			//	cell.text.setString(value);
			//}
		}
	}	
		
		m_result_text.setFont(m_font); // font is a sf::Font

		// set the string to display
		m_result_text.setString(std::string(m_player == player::circle ? "O" : "X") + " make a move");

		// set the character size
		m_result_text.setCharacterSize(25); // in pixels, not points!

		// set the color
		m_result_text.setFillColor(sf::Color::White);

		// set the text style
		m_result_text.setStyle(sf::Text::Bold);
		m_result_text.setPosition(sf::Vector2f(40.f, 280.f));
	
}

uint32_t Game::get_index_by_mouse_position(const sf::Vector2i &mouse_position)
{
	for (int i = 0; i < m_cells.size(); i++)
	{
		const Cell& cell = m_cells[i];
		sf::FloatRect rect_bounds = cell.rect.getGlobalBounds();

		if (rect_bounds.contains(sf::Vector2f((float)mouse_position.x, (float)mouse_position.y))) {
			return i;
		}

	}
	return INVALID_INDEX;
}
