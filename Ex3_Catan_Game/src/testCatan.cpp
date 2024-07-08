#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../hppFiles/doctest.h"
#include "../hppFiles/Catan.hpp"
#include "../hppFiles/Board.hpp"
#include "Player.hpp"
#include "../hppFiles/Card.hpp"
#include "../hppFiles/Settlement.hpp"
#include "../hppFiles/GamePlay.hpp"
#include "../hppFiles/Edge.hpp"
#include "../hppFiles/Tile.hpp"
#include "../hppFiles/Vertex.hpp"

using ariel::Player;
using ariel::Board;
using ariel::Card;
using ariel::Catan;
using ariel::GamePlay;
using ariel::Edge;
using ariel::Tile;
using ariel::Vertex;

TEST_CASE("Initialization and basic functionality tests") {
    std::vector<Player*> players;
    players.push_back(new Player(0, "Player1"));
    players.push_back(new Player(1, "Player2"));
    players.push_back(new Player(2, "Player3"));
    Board board(*players[0], *players[1], *players[2]);
    Catan catan(*players[0], *players[1], *players[2], board);
    board.initializeBoard();
    SUBCASE("Player initialization test") {
        REQUIRE(players.size() == 3);
        REQUIRE(players[0]->getName() == "Player1");
        REQUIRE(players[1]->getPlayerNumber() == 1);
    }
    SUBCASE("Board init test"){
        CHECK(board.isEdgeOwned(0) == 0);
        
    }
    // Delete players to avoid memory leaks
    for (Player* player : players) {
        delete player;
    }
    players.clear();
}


TEST_CASE("Edge functionality tests") {
    Vertex v1(1), v2(2);
    Edge edge(&v1, &v2, 0, -1);

    SUBCASE("Edge initialization") {
        REQUIRE(edge.getVertex1()->getIndex() == 1);
        REQUIRE(edge.getVertex2()->getIndex() == 2);
        REQUIRE(edge.getIndex() == 0);
        REQUIRE(edge.getOwner() == -1);
    }

    SUBCASE("Setting and getting owner") {
        edge.setOwner(1);
        REQUIRE(edge.getOwner() == 1);
    }
}

TEST_CASE("Vertex functionality tests") {
    Vertex vertex(0);

    SUBCASE("Vertex initialization") {
        REQUIRE(vertex.getIndex() == 0);
        REQUIRE(vertex.getOwner() == -1);
        REQUIRE(vertex.getSettlement() == -1);
    }

    SUBCASE("Setting and getting owner and settlement") {
        vertex.setOwner(1);
        vertex.setSettlement(1);
        REQUIRE(vertex.getOwner() == 1);
        REQUIRE(vertex.getSettlement() == 1);
    }

    SUBCASE("Adding and retrieving adjacent tiles") {
        Tile tile("Grain", 8, 0);
        vertex.addAdjacentTile(&tile);
        REQUIRE(vertex.getAdjacentTiles().size() == 1);
        REQUIRE(vertex.getAdjacentTiles()[0]->getIndex() == 0);
    }

    SUBCASE("Adding and retrieving neighbors") {
        Vertex v1(1), v2(2);
        vertex.addNeighbor(&v1, &v2);
        REQUIRE(vertex.getNeighbors().size() == 2);
        REQUIRE(vertex.isNeighbor(v1) == true);
        REQUIRE(vertex.isNeighbor(v2) == true);
    }

    SUBCASE("Adding and retrieving edges") {
        Edge edge(0);
        vertex.addEdge(&edge);
        REQUIRE(vertex.getEdges().size() == 1);
        REQUIRE(vertex.getEdges()[0]->getIndex() == 0);
    }
}
