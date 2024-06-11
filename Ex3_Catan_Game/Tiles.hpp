#ifndef TILES_HPP
#define TILES_HPP

#include <string>

using namespace std;

namespace ariel {
    class Tile {
    public:
        string type;
        int number;

        Tile() : type(""), number(-1) {}
    };
}

#endif
