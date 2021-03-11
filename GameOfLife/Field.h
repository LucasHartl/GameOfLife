#pragma once
#include "Cell.h"
#include <iostream>

class Field
{
private:
	unsigned int _width;
	unsigned int _height;
	Cell** _field;

public:
	Field(unsigned int, unsigned int);
	~Field();

	void update();
	void print();
};

