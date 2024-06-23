// Board.cpp

#include "Board.hpp"
#include <iomanip>
#include <random>
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"

using namespace ariel;
using namespace std;

Board::Board(Player &player1, Player &player2, Player &player3)
{
    // Add players to the players vector
    players.push_back(&player1);
    players.push_back(&player2);
    players.push_back(&player3);
    // Initialize boardVertices with default-constructed Vertex objects
    boardVertices.resize(54);
}
Board::Board() {}

void Board::initializeBoard()
{

    cout << "Initializing board..." << endl;
    int hexagonsPerRow[5] = {3, 4, 5, 4, 3};

    // predefine map:
    vector<string> tileNames = {
        "Field", "Forest", "Field", "Hill",
        "Forest", "Field", "Forest", "Pasture", "Forest", "Dessert", "Pasture",
        "Mountain", "Field", "Pasture", "Mountain",
        "Hill", "Pasture", "Hill", "Mountain"};

    vector<int> tileNumbers = {
        2, 3, 9, 4, 10, 5, 11, 6, 8,
        7, 6, 3, 9, 4, 10, 5, 11, 12, 8}; // deseret have index 19  i let him have number 7
    // defining tiles of the board with index,number of Tile and name of the tile.
    for (int index = 0; index < 19; index++)
    {
        boardTiles.emplace_back(tileNames[index], tileNumbers[index], index + 1);
    }

    // modifing each tile with his vertices.
    vector<vector<size_t>> verticesOfEachTile = {
        {0, 1, 2, 8, 9, 10}, {2, 3, 4, 10, 11, 12}, {4, 5, 6, 12, 13, 14}, {7, 8, 9, 17, 18, 19}, {9, 10, 11, 19, 20, 21}, {11, 12, 13, 21, 22, 23}, {13, 14, 15, 23, 24, 25}, {16, 17, 18, 29, 27, 28}, {18, 19, 20, 31, 29, 30}, {20, 21, 22, 33, 31, 32}, {22, 23, 24, 35, 33, 34}, {24, 25, 26, 37, 36, 35}, {28, 29, 30, 40, 39, 38}, {30, 31, 32, 42, 41, 40}, {32, 33, 34, 44, 43, 42}, {34, 35, 36, 46, 45, 44}, {39, 40, 41, 49, 48, 47}, {41, 42, 43, 51, 50, 49}, {43, 44, 45, 53, 52, 51}};
    // Set vertices of each tile
    // vector<Vertex> vertices(54);
    boardVertices.reserve(54);
    for (size_t i = 0; i < 19; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            boardVertices[verticesOfEachTile[i][j]] = Vertex(verticesOfEachTile[i][j]);
            // vertices[verticesOfEachTile[i][j]] = Vertex(verticesOfEachTile[i][j]);
            boardTiles[i].setVertex(boardVertices[verticesOfEachTile[i][j]]);
        }
    }
    // adding neighbors vertices of each vertex
    boardVertices[0].addNeighbor(&boardVertices[1], &boardVertices[8]);
    boardVertices[1].addNeighbor(&boardVertices[0], &boardVertices[2]);
    boardVertices[2].addNeighbor(&boardVertices[1], &boardVertices[3]);
    boardVertices[2].addNeighbor(&boardVertices[10], &boardVertices[3]);
    boardVertices[3].addNeighbor(&boardVertices[2], &boardVertices[4]);
    boardVertices[4].addNeighbor(&boardVertices[3], &boardVertices[5]);
    boardVertices[4].addNeighbor(&boardVertices[12], &boardVertices[5]);
    boardVertices[5].addNeighbor(&boardVertices[4], &boardVertices[6]);
    boardVertices[6].addNeighbor(&boardVertices[5], &boardVertices[14]);
    boardVertices[7].addNeighbor(&boardVertices[8], &boardVertices[17]);
    boardVertices[8].addNeighbor(&boardVertices[7], &boardVertices[9]);
    boardVertices[8].addNeighbor(&boardVertices[0], &boardVertices[9]);
    boardVertices[9].addNeighbor(&boardVertices[8], &boardVertices[10]);
    boardVertices[9].addNeighbor(&boardVertices[19], &boardVertices[10]);
    boardVertices[10].addNeighbor(&boardVertices[9], &boardVertices[2]);
    boardVertices[10].addNeighbor(&boardVertices[11], &boardVertices[2]);
    boardVertices[11].addNeighbor(&boardVertices[10], &boardVertices[12]);
    boardVertices[11].addNeighbor(&boardVertices[21], &boardVertices[12]);
    boardVertices[12].addNeighbor(&boardVertices[11], &boardVertices[4]);
    boardVertices[12].addNeighbor(&boardVertices[13], &boardVertices[4]);
    boardVertices[13].addNeighbor(&boardVertices[12], &boardVertices[14]);
    boardVertices[13].addNeighbor(&boardVertices[23], &boardVertices[14]);
    boardVertices[14].addNeighbor(&boardVertices[13], &boardVertices[6]);
    boardVertices[14].addNeighbor(&boardVertices[15], &boardVertices[6]);
    boardVertices[15].addNeighbor(&boardVertices[14], &boardVertices[25]);
    boardVertices[16].addNeighbor(&boardVertices[17], &boardVertices[27]);
    boardVertices[17].addNeighbor(&boardVertices[16], &boardVertices[18]);
    boardVertices[17].addNeighbor(&boardVertices[7], &boardVertices[18]);
    boardVertices[18].addNeighbor(&boardVertices[17], &boardVertices[19]);
    boardVertices[18].addNeighbor(&boardVertices[29], &boardVertices[19]);
    boardVertices[19].addNeighbor(&boardVertices[18], &boardVertices[9]);
    boardVertices[19].addNeighbor(&boardVertices[20], &boardVertices[9]);
    boardVertices[20].addNeighbor(&boardVertices[19], &boardVertices[21]);
    boardVertices[20].addNeighbor(&boardVertices[31], &boardVertices[21]);
    boardVertices[21].addNeighbor(&boardVertices[20], &boardVertices[11]);
    boardVertices[21].addNeighbor(&boardVertices[22], &boardVertices[11]);
    boardVertices[22].addNeighbor(&boardVertices[21], &boardVertices[23]);
    boardVertices[22].addNeighbor(&boardVertices[33], &boardVertices[23]);
    boardVertices[23].addNeighbor(&boardVertices[22], &boardVertices[13]);
    boardVertices[23].addNeighbor(&boardVertices[24], &boardVertices[13]);
    boardVertices[24].addNeighbor(&boardVertices[23], &boardVertices[25]);
    boardVertices[24].addNeighbor(&boardVertices[35], &boardVertices[25]);
    boardVertices[25].addNeighbor(&boardVertices[24], &boardVertices[15]);
    boardVertices[25].addNeighbor(&boardVertices[26], &boardVertices[15]);
    boardVertices[26].addNeighbor(&boardVertices[25], &boardVertices[37]);
    boardVertices[27].addNeighbor(&boardVertices[28], &boardVertices[16]);
    boardVertices[28].addNeighbor(&boardVertices[27], &boardVertices[29]);
    boardVertices[28].addNeighbor(&boardVertices[38], &boardVertices[29]);
    boardVertices[29].addNeighbor(&boardVertices[28], &boardVertices[18]);
    boardVertices[29].addNeighbor(&boardVertices[30], &boardVertices[18]);
    boardVertices[30].addNeighbor(&boardVertices[29], &boardVertices[31]);
    boardVertices[30].addNeighbor(&boardVertices[40], &boardVertices[31]);
    boardVertices[31].addNeighbor(&boardVertices[30], &boardVertices[20]);
    boardVertices[31].addNeighbor(&boardVertices[32], &boardVertices[20]);
    boardVertices[32].addNeighbor(&boardVertices[31], &boardVertices[33]);
    boardVertices[32].addNeighbor(&boardVertices[42], &boardVertices[33]);
    boardVertices[33].addNeighbor(&boardVertices[32], &boardVertices[22]);
    boardVertices[33].addNeighbor(&boardVertices[34], &boardVertices[22]);
    boardVertices[34].addNeighbor(&boardVertices[33], &boardVertices[35]);
    boardVertices[34].addNeighbor(&boardVertices[44], &boardVertices[35]);
    boardVertices[35].addNeighbor(&boardVertices[34], &boardVertices[24]);
    boardVertices[35].addNeighbor(&boardVertices[36], &boardVertices[24]);
    boardVertices[36].addNeighbor(&boardVertices[35], &boardVertices[37]);
    boardVertices[36].addNeighbor(&boardVertices[46], &boardVertices[37]);
    boardVertices[37].addNeighbor(&boardVertices[36], &boardVertices[26]);
    boardVertices[38].addNeighbor(&boardVertices[39], &boardVertices[28]);
    boardVertices[39].addNeighbor(&boardVertices[38], &boardVertices[40]);
    boardVertices[39].addNeighbor(&boardVertices[40], &boardVertices[47]);
    boardVertices[40].addNeighbor(&boardVertices[39], &boardVertices[30]);
    boardVertices[40].addNeighbor(&boardVertices[41], &boardVertices[30]);
    boardVertices[41].addNeighbor(&boardVertices[40], &boardVertices[42]);
    boardVertices[41].addNeighbor(&boardVertices[49], &boardVertices[42]);
    boardVertices[42].addNeighbor(&boardVertices[41], &boardVertices[32]);
    boardVertices[42].addNeighbor(&boardVertices[43], &boardVertices[32]);
    boardVertices[43].addNeighbor(&boardVertices[42], &boardVertices[44]);
    boardVertices[43].addNeighbor(&boardVertices[51], &boardVertices[44]);
    boardVertices[44].addNeighbor(&boardVertices[43], &boardVertices[34]);
    boardVertices[44].addNeighbor(&boardVertices[45], &boardVertices[34]);
    boardVertices[45].addNeighbor(&boardVertices[44], &boardVertices[46]);
    boardVertices[45].addNeighbor(&boardVertices[53], &boardVertices[46]);
    boardVertices[46].addNeighbor(&boardVertices[45], &boardVertices[36]);
    // last line of Hexagons
    boardVertices[47].addNeighbor(&boardVertices[48], &boardVertices[39]);
    boardVertices[48].addNeighbor(&boardVertices[47], &boardVertices[49]);
    boardVertices[49].addNeighbor(&boardVertices[48], &boardVertices[41]);
    boardVertices[49].addNeighbor(&boardVertices[50], &boardVertices[41]);
    boardVertices[50].addNeighbor(&boardVertices[49], &boardVertices[51]);
    boardVertices[51].addNeighbor(&boardVertices[50], &boardVertices[43]);
    boardVertices[51].addNeighbor(&boardVertices[52], &boardVertices[43]);
    boardVertices[52].addNeighbor(&boardVertices[51], &boardVertices[53]);
    boardVertices[53].addNeighbor(&boardVertices[52], &boardVertices[45]);

    for (size_t i = 0; i < 72; ++i)
    {
        boardEdges.emplace_back(i);
    }

    vector<vector<size_t>> edgesOnBoard = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {0, 8}, {2, 10}, {4, 12}, {6, 14}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {7, 17}, {9, 19}, {11, 21}, {13, 23}, {15, 25}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {16, 27}, {18, 29}, {20, 31}, {22, 33}, {24, 35}, {26, 37}, {27, 28}, {28, 29}, {29, 30}, {30, 31}, {31, 32}, {32, 33}, {33, 34}, {34, 35}, {35, 36}, {36, 37}, {28, 38}, {30, 40}, {32, 42}, {34, 44}, {36, 46}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {44, 45}, {45, 46}, {39, 47}, {41, 49}, {43, 51}, {45, 53}, {47, 48}, {48, 49}, {49, 50}, {50, 51}, {51, 52}, {52, 53}};

    // Set the vertices for each edge
    for (size_t i = 0; i < 72; ++i)
    {
        boardEdges[i].setVertices(&boardVertices[edgesOnBoard[i][0]], &boardVertices[edgesOnBoard[i][1]]);
        boardVertices[edgesOnBoard[i][0]].addEdge(&boardEdges[i]);
        boardVertices[edgesOnBoard[i][1]].addEdge(&boardEdges[i]);
    }

    // // For demonstration purposes, print out the tiles and their vertices****self debug
    cout << "\nFor demonstration purposes, print out the tiles and their vertices:(in Board.cpp line 175)" << endl;
    // for (auto &tile : boardTiles)
    // {
    //     cout << "Tile Index: " << tile.getIndex() << ", Tile Number: " << tile.getNumber() << ", Tile resource: " << tile.getResource() << endl;
    //     // cout << "Vertices: ";
    //     // for (auto &vertex : tile.getVertices())
    //     // {
    //     //     cout << (*vertex).getIndex() << " "; // Using dereferencing
    //     // }
    //     // cout << endl;
    // }
    // Print each edge with its connected vertices
    // cout << "\nEdges and their connected vertices 2 try:" << endl;
    // for (const auto &edge : boardEdges)
    // {
    //     auto vertex1 = edge.getVertex1(); // Assuming getVertices() returns a pair of Vertex pointers
    //     auto vertex2 = edge.getVertex2();
    //     cout << "Edge " << edge.getIndex() << ": (" << vertex1->getIndex() << ", " << vertex2->getIndex() << ")" << endl;
    // }
    // cout << "what boardEdges size? " << boardEdges.size() << endl;
    // for (int i = 0; i < boardEdges.size(); i++)
    // {

    //     auto vertex1 = boardEdges[i].getVertex1(); // Assuming getVertices() returns a pair of Vertex pointers
    //     auto vertex2 = boardEdges[i].getVertex2();
    //     cout << "Edge number: " << boardEdges[i].getIndex() << " (" << vertex1->getIndex() << ", " << vertex2->getIndex() << ")" << endl;
    // }
}
// check board to verify that player can set settlements or roads on board on specific vertices.
bool Board::checkInitialPlacement(Player &player, size_t vertexIndex1, size_t vertexIndex2)
{

    // Check if vertexIndex is valid
    if (vertexIndex1 >= boardVertices.size() || vertexIndex1 < 0 || vertexIndex2 >= boardVertices.size() || vertexIndex2 < 0)
    {
        cerr << "Invalid vertex index." << endl;
        return false;
    }
    int playerNum = player.getPlayerNumber();
     checkRoadPlacementAndSet(playerNum, vertexIndex1, vertexIndex2);
    //checkSettlementPlacementAndSet(int playerNumber, size_t vertexIndex)
     checkSettlementPlacementAndSet(playerNum, vertexIndex1);
    // Set owner of the vertex to player number
   // vertexForSettlement.setOwner(player.getPlayerNumber());

    
    return true;
}

// Check if the player can place a road adjacent to their settlement
bool Board::canPlaceRoad(Player &player, size_t vertexIndex)
{
    // Check if vertexIndex is valid
    if (vertexIndex >= boardVertices.size() || vertexIndex < 0)
    {
        cerr << "Invalid vertex index." << endl;
        return false;
    }

    // Get the vertex at the specified index
    const Vertex &vertex = boardVertices[vertexIndex];

    // Check if the vertex is owned by the player
    if (vertex.getOwner() != player.getPlayerNumber())
    {
        cerr << "Vertex " << vertexIndex << " does not belong to the player." << endl;
        return false;
    }

    // Check if the vertex has adjacent settlements owned by the player
    const vector<Vertex *> &adjacentTiles = vertex.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentTiles)
    {
        if (adjacentVertex->getOwner() == player.getPlayerNumber())
        {
            // Player can place road adjacent to their settlement
            return true;
        }
    }

    cerr << "No adjacent settlement owned by the player found." << endl;
    return false;
}

bool Board::checkAdjacentSettlement(const Vertex &vertex, int playerNumber)
{
    const vector<Vertex *> &adjacentTiles = vertex.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentTiles)
    {
        if (adjacentVertex->getOwner() == playerNumber)
        {
            return true;
        }
    }
    cerr << "No adjacent settlement owned by the player found." << endl;
    return false;
}

void Board::checkSettlementPlacementAndSet(int playerNumber, size_t vertexIndex)
{
    // Check if vertexIndex is valid
    if (vertexIndex >= boardVertices.size() || vertexIndex < 0)
    {
        cerr << "Invalid vertex index." << endl;
       
    }

    // Get the vertex at the specified index
    Vertex &vertex = boardVertices[vertexIndex];

    // Check if the vertex is already occupied by a settlement or city
    if (vertex.getOwner() != -1)
    {
        cerr << "Vertex is already occupied." << endl;
        
    }

    // Check adjacency of vertecies to the vertex for existing settlements or cities
    const vector<Vertex *> &adjacentPlots = vertex.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            cerr << "Adjacent vertex " << adjacentVertex->getIndex() << " already occupied." << endl;
        }
    }
    // Set owner of the vertex to player number
    vertex.setOwner(playerNumber);

}

void Board::checkRoadPlacementAndSet(int playerNum, size_t vertexIndex1, size_t vertexIndex2)
{
    // Check if vertex indices are valid
    if (vertexIndex1 >= boardVertices.size() || vertexIndex2 >= boardVertices.size() || vertexIndex1 == vertexIndex2 || vertexIndex1 < 0 || vertexIndex2 < 0)
    {
        cerr << "Invalid vertex indices." << endl;
    }

    // Get the vertices at the specified indices
     Vertex &v1 = boardVertices[vertexIndex1];
     Vertex &v2 = boardVertices[vertexIndex2];

    bool hasAdjacentSettlemnt =  checkAdjacentSettlement(v2, playerNum);


    if(!hasAdjacentSettlemnt){
        cerr << "Edge index has no adjacent settlement." << endl;
    }
  //  Check if the edge to place a road on is occupied or not
    int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
    if (edgeIndex != -1)
    {
        if (boardEdges[edgeIndex].getOwner() != -1)
        {
            cerr << "Edge is already occupied." << endl;
       
        }
    }
  

    // Set owner of the edge to player number
   // boardEdges[edgeIndex].setOwner(player.getPlayerNumber());
    // Check if the road is already occupied
    int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
    if (edgeIndex != -1 && boardEdges[edgeIndex].getOwner() != -1)
    {
        cerr << "Road is already occupied." << endl;
    }

    

    // Check if the player has a road connected to one of the vertices
    const vector<Edge *> &adjacentEdges1 = v1.getEdges();
    const vector<Edge *> &adjacentEdges2 = v2.getEdges();
    for (const Edge *edge1 : adjacentEdges1)
    {
        if (edge1->getOwner() == playerNum)
        {
            for (const Edge *edge2 : adjacentEdges2)
            {
                if (edge2->getOwner() == playerNum)
                {
                    if (edgeIndex != -1)
                    {
                          // Set owner of the vertex to player number
                     // Set the owner of the edge to the playerID
                    boardEdges[edgeIndex].setOwner(playerNum);
                        cout << " Road set on index " << edgeIndex << " of edges.\n";
                    }
                }
            }
        }
    }

    cerr << "Player does not have the required adjacent structures." << endl;
}

bool Board::checkCityPlacement(int playerId, size_t vertexIndex)
{
    // Check if vertexIndex is valid
    if (vertexIndex >= boardVertices.size() || vertexIndex < 0)
    {
        cerr << "Invalid vertex index." << endl;
        return false;
    }

    // Get the vertex at the specified index
    Vertex &vertexForSettlement = boardVertices[vertexIndex];
    // Check if the vertex is already occupied by a settlement or city
    if (vertexForSettlement.getOwner() != -1)
    {
        cerr << "Vertex " << vertexIndex << "is already has owner." << endl;
        return false;
    }

    // Check if the vertex is adjacent to a vertex that is already occupied by one of the players
    const vector<Vertex *> &adjacentTiles = vertexForSettlement.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentTiles)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            cerr << "Adjacent vertex " << adjacentVertex->getIndex() << " has  owner, its not possible to place on " << vertexIndex << endl;
            return false;
        }
    }
    return true;
}
// New function to get a reference to the board tiles
vector<Tile> &Board::getBoardTiles()
{
    return boardTiles;
}

int Board::getEdge(size_t vertexIndex1, size_t vertexIndex2)
{
    if (vertexIndex1 > vertexIndex2)
    {
        swap(vertexIndex1, vertexIndex2);
    }
    for (int i = 0; i < 72; i++)
    {
        if (boardEdges[i].getVertex1()->getIndex() == vertexIndex1 && boardEdges[i].getVertex2()->getIndex() == vertexIndex2)
        {
            return i;
        }
    }
    return -1;
}

// void Board::setSettlement(int row, int col, const string& player) {
//     if (!isValidPosition(row, col)) {
//         cout << "Invalid position" << endl;
//         return;
//     }

// void Board::setRoad(int row, int col, const string& player) {
//     if (!isValidPosition(row, col)) {
//         cout << "Invalid position" << endl;
//         return;
//     }
//     // Check if the location is unoccupied
//     if (roads[row][col] == " " || (roads[row][col].length() == 1 && isalpha(roads[row][col][0]))) {
//         roads[row][col] = "R-" + player; // For example, "R-p1"
//     } else {
//         cout << "Position already occupied" << endl;
//     }
// }

void Board::placeRoad(const vector<string> &places, const vector<int> &placesNum, char playerID)
{
}

void Board::rollDice()
{
    random_device rd;
    mt19937 gen(rd());

    vector<int> diceProbabilities = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

    discrete_distribution<int> diceDistribution(diceProbabilities.begin(), diceProbabilities.end());
}

void Board::printBoard() const
{
    // Implementation for printing the board
}

bool Board::canPlaceInitialSettlementAndRoad(Player &player, size_t vertexIndex, size_t vertexIndex2)
{
    // Check if vertexIndex is valid
    if (vertexIndex >= boardVertices.size() || vertexIndex < 0 || vertexIndex2 >= boardVertices.size() || vertexIndex2 < 0)
    {
        cerr << "Invalid vertex index." << endl;
        return false;
    }

    // Get the vertex at the specified index
    Vertex &vertex = boardVertices[vertexIndex];

    // Check if the vertex is already occupied by a settlement or city
    if (vertex.getOwner() != -1)
    {
        cerr << "Vertex is already occupied." << endl;
        return false;
    }

    // Check if the vertex is adjacent to a vertex that is already occupied by one of the players
    const vector<Vertex *> &adjacentPlots = vertex.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            cerr << "Adjacent vertex " << adjacentVertex->getIndex() << " already occupied." << endl;
            return false;
        }
    }

    // Check if the edge we are trying to place a road on is occupied
    int edgeIndex = getEdge(vertexIndex, vertexIndex2);
    if (edgeIndex != -1)
    {
        if (boardEdges[edgeIndex].getOwner() != -1)
        {
            cerr << "Edge is already occupied." << endl;
            return false;
        }
    }

    // Set the owner of the vertex to the playerID
    vertex.setOwner(player.getPlayerNumber());

    // Set the owner of the edge to the playerID
    boardEdges[edgeIndex].setOwner(player.getPlayerNumber());

    // Give the player the resources that the vertex sits on
    for (int i = 0; i < 19; i++)
    {
        const vector<Vertex *> &vertices = boardTiles[i].getVertices();
        for (Vertex *v : vertices)
        {
            if (v->getIndex() == vertexIndex)
            {
                if (boardTiles[i].getResource() == "Mountains")
                {
                    player.addResource("Ore", 1);
                }
                else if (boardTiles[i].getResource() == "Pasture")
                {
                    player.addResource("Wool", 1);
                }
                else if (boardTiles[i].getResource() == "Forest")
                {
                    player.addResource("Wood", 1);
                }
                else if (boardTiles[i].getResource() == "Agricultural")
                {
                    player.addResource("Wheat", 1);
                }
                else if (boardTiles[i].getResource() == "Hills")
                {
                    player.addResource("Brick", 1);
                }
            }
        }
    }

    return true;
}

void distributeResources()
{
    // distribute resource by indexs
    for (int i = 0; i < 19; i++)
    {
        const vector<Vertex *> &vertices = boardTiles[i].getVertices();
        for (Vertex *v : vertices)
        {
            if (v->getIndex() == vertexIndex1)
            {
                if (boardTiles[i].getResource() == "Mountains")
                {
                    player.addResource("Ore", 1);
                }
                else if (boardTiles[i].getResource() == "Pasture")
                {
                    player.addResource("Wool", 1);
                }
                else if (boardTiles[i].getResource() == "Forest")
                {
                    player.addResource("Wood", 1);
                }
                else if (boardTiles[i].getResource() == "Agricultural")
                {
                    player.addResource("Wheat", 1);
                }
                else if (boardTiles[i].getResource() == "Hills")
                {
                    player.addResource("Brick", 1);
                }
            }
        }
    }
}
