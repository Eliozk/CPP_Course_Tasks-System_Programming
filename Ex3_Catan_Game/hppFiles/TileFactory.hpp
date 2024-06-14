// // factory pattern to create different types of tiles
// #ifndef TILEFACTORY_HPP
// #define TILEFACTORY_HPP

// #include "Tile.hpp"
// #include "Forest.hpp"
// #include "Hills.hpp"
// // Include other specific tile headers
// namespace ariel
// {
//     class TileFactory
//     {
//     public:
//         static Tile *createTile(const std::string &type, int number)
//         {
//             if (type == "Forest")
//                 return new Forest(number);
//             if (type == "Hills")
//                 return new Hills(number);
//             // Add other tile types
//             return nullptr;
//         }
//     };
// }
// #endif // TILEFACTORY_HPP
