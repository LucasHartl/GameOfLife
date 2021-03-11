#include <iostream>
#include "GameOfLife.h"
#include "Field.h"

int main()
{
    system("title Game Of Life Console");
    srand(time(NULL));

    GameOfLife game = GameOfLife();
    game.run();

    system("pause");
    return 0;
}
