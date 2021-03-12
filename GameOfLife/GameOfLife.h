#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>

class GameOfLife
{
private:
	Field *_field;
	unsigned int _width;
	unsigned int _height;
	unsigned int _cellSize;


public:
	GameOfLife(unsigned int, unsigned int, unsigned int);
	~GameOfLife();

	void run();
};
