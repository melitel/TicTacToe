#pragma once
#include <array>

class Board
{
public:
	bool make_move(uint32_t index, char value);
	void initialize();
	bool get_value_by_index(uint32_t index, char *value) {
		if (index < m_array.size())
		{
			*value = m_array[index];
			return true;
		}
		
		return false;
	}
	char get_value_by_index(uint32_t index) {
		return m_array[index];
	}
	enum class state { ingame, win, draw };
	state update_state();

private:
	bool is_win(uint32_t index1, uint32_t index2, uint32_t index3);
	std::array<char, 9> m_array;

};

