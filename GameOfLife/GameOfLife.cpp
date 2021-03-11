#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
	this->_field = new Field(20, 20);
}


GameOfLife::~GameOfLife()
{
    this->_field->~Field();
}


void GameOfLife::run()
{
    // game loop
    for (int i = 0; i < 100; i++)
    {
        this->_field->print();
        this->_field->update();
        system("cls");
    }
}