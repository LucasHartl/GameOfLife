#include <iostream>
#include "GameOfLife.h"
#include "Field.h"

int main()
{
    system("title Game Of Life Console");
    srand(time(NULL));

    GameOfLife *game = new GameOfLife(75, 75, 10);
    game->run();
    delete game;

    //system("pause");
    return 0;
}
