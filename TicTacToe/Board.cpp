#include "Board.h"

void Board::make_move(uint32_t move, char value)
{
	uint32_t index = move - 1;
	m_array[index] = value;

}

void Board::initialize()
{
	char val = '1';

	for (char &cell : m_array)
	{
		cell = val++;		
	}
}
