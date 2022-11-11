#include "Game.h"

#include <iostream>

void Game::run()
{
	initialize();

	while (true)
	{
		gather_input();
		update();
		draw();
	}
}

void Game::gather_input()
{
	std::cout << "Make your move, " << (m_player == player::circle ? 'O' : 'X') << std::endl;
	uint32_t input{ 10 };
	std::cin >> input;
	if (input > 0 && input <= 9)
	{
		m_board.make_move(input, (m_player == player::circle ? 'O' : 'X'));
	}
}

void Game::draw()
{
	uint32_t index{ 0 };
	char value;

	while (m_board.get_value_by_index(index++, &value)) {

		std::cout << value;
		if (index%3 == 0)
		{
			std::cout << '\n';
		}
	}	

	std::cout << std::endl;
}

void Game::update()
{
	if (m_player == player::circle)
	{
		m_player = player::cross;
	}
	else {
		m_player = player::circle;
	}
}

void Game::initialize()
{
	m_board.initialize();
	draw();
}
 