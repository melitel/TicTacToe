#include "Game.h"

#include <iostream>
#include <string>

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

	while (m_game_state == Board::state::ingame)
	{
		gather_input();
		update();
		draw();
	}
}

void Game::gather_input()
{
	std::cout << "Make your move, " << (m_player == player::circle ? 'O' : 'X') << std::endl;
	std::string input;
	std::cin >> input;
	uint32_t input_number = isNumber(input) ? std::stoi(input) : 0;
	if (input_number > 0 && input_number <= 9)
	{			
		if (m_board.make_move(input_number, (m_player == player::circle ? 'O' : 'X'))) {

		}
		else
		{
			std::cout << "Make another move" << std::endl;
		}
	}
}

void Game::draw()
{
	if (m_game_state == Board::state::draw)
	{
		std::cout << "It's a draw" << std::endl;
	}
	else if (m_game_state == Board::state::win)
	{
		std::cout << (m_player == player::circle ? 'O' : 'X') << " wins" << std::endl;
	}
	else
	{
		uint32_t index{ 0 };
		char value;

		while (m_board.get_value_by_index(index++, &value)) {

			std::cout << value;
			if (index % 3 == 0)
			{
				std::cout << '\n';
			}
		}

		std::cout << std::endl;		
	}
}

void Game::update()
{
	m_game_state = m_board.update_state();

	if (m_game_state == Board::state::ingame)
	{
		if (m_player == player::circle)
		{
			m_player = player::cross;
		}
		else {
			m_player = player::circle;
		}
	}	
}

void Game::initialize()
{
	m_game_state = Board::state::ingame;
	m_board.initialize();
	draw();
}
 