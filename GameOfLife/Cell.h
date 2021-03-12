#pragma once
#include <iostream>


/*
	This class is representing the cell, the tiniest element of the game field.
	It contains the current and the next-generation state (alive, dead)
*/
class Cell
{
private:
	bool _alive;
	bool _next_state;


public:
	// Standard constructor
	Cell();

	// Standard destructor
	~Cell();


	// Setter
	void set_alive(bool);
	void set_next_state(bool);

	// Getter
	bool is_alive();
	bool get_next_state();
};
