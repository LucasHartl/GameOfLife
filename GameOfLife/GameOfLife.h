#pragma once
#include "Field.h"
#include <SFML/Graphics.hpp>

class GameOfLife
{
private:
	Field *_field;


public:
	GameOfLife();
	~GameOfLife();

	void run();
};
