#include "GameOfLife.h"

GameOfLife::GameOfLife(unsigned int h, unsigned int w, unsigned int cellSize)
{
    this->_height = h;
    this->_width = w;
    this->_cellSize = cellSize;
	this->_field = new Field(w, h);
}


GameOfLife::~GameOfLife()
{
    this->_field->~Field();
}


void GameOfLife::run()
{
    sf::RenderWindow window(sf::VideoMode(this->_width * this->_cellSize, this->_height * this->_cellSize), "Game Of Life");
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(static_cast<float>(this->_cellSize), static_cast<float>(this->_cellSize)));
    cell.setOutlineColor(sf::Color::Blue);
    cell.setOutlineThickness(2);

    // game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        this->_field->update();

        window.clear();

        for (register unsigned int h = 0; h < this->_field->get_height(); h++)
        {
            for (register unsigned int w = 0; w < this->_field->get_width(); w++)
            {
                if (this->_field->get_status(h, w))
                {
                    // the cell is alive
                    cell.setFillColor(sf::Color::White);
                }
                else
                {
                    // dead cell
                    cell.setFillColor(sf::Color::Black);
                }
                cell.setPosition(sf::Vector2f(static_cast<float>(w * this->_cellSize), static_cast<float>(h * this->_cellSize)));
                window.draw(cell);
            }
        }

        window.display();
    }
}