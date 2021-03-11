#include "Cell.h"

Cell::Cell()
{
	this->_alive = rand() % 2;
	this->_next_state = false;
}


Cell::~Cell()
{

}


bool Cell::is_alive()
{
	return this->_alive;
}


bool Cell::get_next_state()
{
	return this->_next_state;
}


void Cell::set_alive(bool b)
{
	this->_alive = b;
}


void Cell::set_next_state(bool b)
{
	this->_next_state = b;
}
