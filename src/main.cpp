#include <stdlib.h>
#include <iostream>

#include "engine/Game.h"
#include "engine/math/Vector2D.h"

int main(int argc, char* args[]) {

    Vector2D vector(1.0f, 2.0f);

    // std::cout << vector.toString() << std::endl;

    Game game(1920, 1080, false);

    game.start();

    return 0;
}