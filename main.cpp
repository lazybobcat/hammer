#include <iostream>
#include "application.h"

using namespace std;

int main()
{
    const unsigned int width = 1024, height = width * 1/2;
    try {
        Application game(width, height, "Hammer - Smash'em");
        game.run();
    } catch(std::exception& e) {
        std::cerr << "Game ended unexpectedely : " << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

