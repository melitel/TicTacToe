#include "Board.h"
#include <string>

bool Board::make_move(uint32_t index, char value)
{
	if (m_array[index] == 'O' || m_array[index] == 'X') {
		return false;
	}

	m_array[index] = value;
	return true;
}

void Board::initialize()
{
	//char val = '1';

	for (char &cell : m_array)
	{
		cell = '.';
	}
}

Board::state Board::update_state()
{
	state my_state{state::draw};

	//if no more space to play
	for (int i = 0; i < m_array.size(); ++i)
	{
		if (m_array[i] == '.')
		{
			my_state = state::ingame;
			break;
		}		
	}

	//if there is a win combination
	if (is_win(0, 3, 6))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 0, 3, 6 });
	}
	else if (is_win(1, 4 ,7))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 1, 4 ,7 });
	}
	else if (is_win(2 , 5, 8))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 2 , 5, 8 });
	}
	else if (is_win(0, 1, 2))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 0, 1, 2 });
	}
	else if (is_win(3, 4, 5))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 3, 4, 5 });
	}
	else if (is_win(6, 7, 8))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 6, 7, 8 });
	}
	else if (is_win(0, 4, 8))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 0, 4, 8 });
	}
	else if (is_win(2, 4, 6))
	{
		my_state = state::win;
		win_combination.insert(win_combination.end(), { 2, 4, 6 });
	}

	//else continue to play
	return my_state;
}

bool Board::is_win(uint32_t index1, uint32_t index2, uint32_t index3)
{

	if (m_array[index1] == m_array[index2] && m_array[index1] == m_array[index3] && m_array[index1] != '.')
	{
		return true;
	}

	return false;
}
