#pragma once
#include <array>

class Board
{
public:
	void make_move(uint32_t move, char value);
	void initialize();
	bool get_value_by_index(uint32_t index, char *value) {
		if (index < m_array.size())
		{
			*value = m_array[index];
			return true;
		}
		
		return false;
	}

private:
	std::array<char, 9> m_array;
};

