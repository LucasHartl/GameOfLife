#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>


/*
	This class is handling the whole game, including the graphical user interface.
	It contains the game field and some member variables in order to describe the game (width, height and cellSize).
*/
class GameOfLife
{
private:
	Field *_field;
	unsigned int _width;
	unsigned int _height;
	unsigned int _cellSize;


public:
	// A constructor to create a new instance of the game, taking the parameters to describe the game elements
	GameOfLife(unsigned int height, unsigned int width, unsigned int cellSize);
	
	// A destructor, deleting the game field on the heap
	~GameOfLife();

	// This method is containing the game loop and handling the game
	void run();
};
