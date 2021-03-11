#include "Field.h"

Field::Field(unsigned int w, unsigned int h)
{
	this->_width = w;
	this->_height = h;

	/*
		[0][0]; [0][1]; [0][2]; ...
		[1][0]; [1][1]; [1][2]; ...
		[2][0]; [2][1]; [2][2]; ...
		...
	*/
	_field = new Cell * [h];
	for (register unsigned int i = 0; i < h; i++)
	{
		_field[i] = new Cell[w];
	}
}


Field::~Field()
{
	for (register unsigned int h = 0; h < this->_height; h++)
	{
		delete[] this->_field[h];
	}
	delete[] this->_field;
}


void Field::update()
{
	// debugging message
	//std::cout << std::endl << "Printing the amount of neighbours:" << std::endl;

	// calculate the next state of each cell
	for (register unsigned int h = 0; h < this->_height; h++)
	{
		for (register unsigned int w = 0; w < this->_width; w++)
		{
			// the counter variable is used for counting the current amount of neighbours
			unsigned int counter = 0;

			// check if the current cell ist on [0][0] (left upper corner)
			if (h == 0 && w == 0)
			{
				if (this->_field[h][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
			}
			// check if the current cell is on [0][max] (right upper corner)
			else if (h == 0 && w == this->_width - 1)
			{
				if (this->_field[h][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
			}
			// check if the current cell is on [max][0] (left lower corner)
			else if (h == this->_height - 1 && w == 0)
			{
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h][w + 1].is_alive()) { counter++; }
			}
			// check if the current cell is on [max][max] (right lower corner)
			else if (h == this->_height - 1 && w == this->_width - 1)
			{
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h][w - 1].is_alive()) { counter++; }
			}
			// check if the current cell is on [0][...] (upper first line)
			else if (h == 0)
			{
				if (this->_field[h][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
				if (this->_field[h + 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h][w + 1].is_alive()) { counter++; }
			}
			// check if the current cell is on [...][0] (left line)
			else if (w == 0)
			{
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
			}
			// check if the current cell is on [...][max] (right line)
			else if (w == this->_width - 1)
			{
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
			}
			// check if the current cell is on [max][...] (lower line)
			else if (h == this->_height - 1)
			{
				if (this->_field[h][w - 1].is_alive()) { counter++; }
				if (this->_field[h - 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h][w + 1].is_alive()) { counter++; }
				
			}
			// if the current cell is not at any corner / edge, count every living neighbour cell
			else
			{
				if (this->_field[h - 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h - 1][w].is_alive()) { counter++; }
				if (this->_field[h - 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w + 1].is_alive()) { counter++; }
				if (this->_field[h + 1][w].is_alive()) { counter++; }
				if (this->_field[h + 1][w - 1].is_alive()) { counter++; }
				if (this->_field[h][w - 1].is_alive()) { counter++; }
			}

			// print the field with the amount of neighbours
			//std::cout << counter;

			// store the next generation with the rules of the game
			if (this->_field[h][w].is_alive() && (counter < 2 || counter > 3))
			{
				this->_field[h][w].set_next_state(false);
			}
			else if (
				(this->_field[h][w].is_alive() && (counter == 2 || counter == 3)) ||
				(!this->_field[h][w].is_alive() && counter == 3))
			{
				this->_field[h][w].set_next_state(true);
			}
			
		}

		//std::cout << std::endl;
	}

	// load the results into the current state(_alive) and set the next generation state to false
	for (register unsigned int h = 0; h < this->_height; h++)
	{
		for (register unsigned int w = 0; w < this->_width; w++)
		{
			this->_field[h][w].set_alive(this->_field[h][w].get_next_state());
			this->_field[h][w].set_next_state(false);
		}
	}
}


void Field::print()
{
	std::cout << "Printing the Field:" << std::endl;

	for (unsigned int h = 0; h < this->_height; h++)
	{
		for (unsigned int w = 0; w < this->_width; w++)
		{
			std::cout << this->_field[h][w].is_alive() ? "1": "0";
		}

		std::cout << std::endl;
	}
}