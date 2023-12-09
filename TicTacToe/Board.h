#pragma once
#include <array>
#include <vector>

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
	std::vector<int> get_win_combo() {
		return win_combination;
	}
	char get_value_by_index(uint32_t index) {
		return m_array[index];
	}
	enum class state { ingame, win, draw };
	state update_state();

private:
	bool is_win(uint32_t index1, uint32_t index2, uint32_t index3);
	std::array<char, 9> m_array;
	std::vector<int> win_combination;

};

