#pragma once
#include "Cell.h"
#include <iostream>


/*
	This class is handling the game field, including the whole game logic.
	It contains a 2D array of cells and the attributes for the size of the game field.
*/
class Field
{
private:
	unsigned int _width;
	unsigned int _height;
	Cell** _field;

public:
	// The constructor, taking the width and the height
	Field(unsigned int width, unsigned int height);

	// The destructor is deleting the game fild on the heap
	~Field();

	// Calculate the next generation and store the last calculated generation values into the current member variables.
	void update();

	// Print the field to the console, used for debugging the program
	void print();

	// Getter
	unsigned int get_width();
	unsigned int get_height();
	bool get_status(unsigned int, unsigned int);
};

