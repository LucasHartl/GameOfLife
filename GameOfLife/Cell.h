#pragma once
#include <iostream>

class Cell
{
private:
	bool _alive;
	bool _next_state;


public:
	Cell();
	~Cell();

	// Setter
	void set_alive(bool);
	void set_next_state(bool);

	// Getter
	bool is_alive();
	bool get_next_state();
};
