// Board.cpp

#include "Board.hpp"
#include <iomanip>
#include <random>
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"
#include "Tile.hpp"
#include "Settlement.hpp"
#include "Card.hpp"
#include <unordered_set>
#include <functional>
#include <stack>

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
    for (size_t i = 0; i < 72; ++i)
    {
        boardEdges.emplace_back(i);
    }
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

    vector<vector<size_t>> edgesOnBoard = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {0, 8}, {2, 10}, {4, 12}, {6, 14}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {7, 17}, {9, 19}, {11, 21}, {13, 23}, {15, 25}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {16, 27}, {18, 29}, {20, 31}, {22, 33}, {24, 35}, {26, 37}, {27, 28}, {28, 29}, {29, 30}, {30, 31}, {31, 32}, {32, 33}, {33, 34}, {34, 35}, {35, 36}, {36, 37}, {28, 38}, {30, 40}, {32, 42}, {34, 44}, {36, 46}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {44, 45}, {45, 46}, {39, 47}, {41, 49}, {43, 51}, {45, 53}, {47, 48}, {48, 49}, {49, 50}, {50, 51}, {51, 52}, {52, 53}};

    // Set the vertices for each edge
    for (size_t i = 0; i < 72; ++i)
    {
        boardEdges[i].setVertices(&boardVertices[edgesOnBoard[i][0]], &boardVertices[edgesOnBoard[i][1]]);
        boardVertices[edgesOnBoard[i][0]].addEdge(&boardEdges[i]);
        boardVertices[edgesOnBoard[i][1]].addEdge(&boardEdges[i]);
    }
}

const vector<Vertex> &Board::getBoardVertices() const
{
    return boardVertices;
}

bool Board::checkInitialPlacement(Player &player, size_t vertexIndex1, size_t vertexIndex2)
{
    // Check if vertexIndex is valid
    if (vertexIndex1 >= boardVertices.size() || vertexIndex1 < 0 || vertexIndex2 >= boardVertices.size() || vertexIndex2 < 0)
    {
        cerr << "Invalid vertex index." << endl;
        return false;
    }

    // Get the vertex at the specified index
    Vertex &vertexForSettlement = boardVertices[vertexIndex1];
    const Vertex vertexForRoad = boardVertices[vertexIndex2];
    int playerNumber = player.getPlayerNumber();
    // Check if the vertex is already occupied by a settlement or city
    if (vertexForSettlement.getOwner() != -1)
    {
        cerr << "Vertex is already occupied." << endl;
        return false;
    }
    // Check if the vertex is adjacent to a vertex that is already occupied by one of the players
    const vector<Vertex *> &adjacentPlots = vertexForSettlement.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            cout << "Adjacent vertex " << adjacentVertex->getIndex() << " already occupied." << endl;
            return false;
        }
    }
// Check if the edge we are trying to place a road on is occupied
    int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
    if (edgeIndex == -1) // if this edge not existed it is -1
    {
        return false;
    }
    if (boardEdges[edgeIndex].getOwner() != -1) // if this edge has owner it is -1.
    {
        cerr << "Edge between " << vertexIndex2 << " and " << vertexIndex2 << " is already occupied." << endl;
        return false;
    }
    // Set the owner of the vertex to the player number
    boardVertices[vertexIndex1].setOwner(player.getPlayerNumber());
    boardVertices[vertexIndex1].setSettlement(1);

    // add 1 point for each settlement
    player.add1point();
    // add settlement to player settlements.
    player.addSettlement(vertexIndex1);
    // update boardTiles at this vertex of this settlement of player.
    updateTileAtVertex(vertexIndex1, player);
    

    // Set the owner of the edge to the player number
    boardEdges[edgeIndex].setOwner(player.getPlayerNumber());

    player.addRoad(edgeIndex);
    // distribute resource by vertex of the settlement of the player.
    for (int i = 0; i < 19; i++)
    {
        const vector<Vertex *> &vertices = boardTiles[i].getVertices();
        for (Vertex *v : vertices)
        {

            if (v->getIndex() == vertexIndex1)
            {

                if (boardTiles[i].getResource() == "Grain") // משדה מקבלים תבואה
                {
                    player.addResource("Grain", 1);
                }
                else if (boardTiles[i].getResource() == "Lumber") // עצים חתוכים לבנייה
                {
                    player.addResource("Lumber", 1);
                }
                else if (boardTiles[i].getResource() == "Brick") // לבנים מגבעות
                {
                    player.addResource("Brick", 1);
                }
                else if (boardTiles[i].getResource() == "Ore") // נחושת מהרים
                {
                    player.addResource("Ore", 1);
                }
                else if (boardTiles[i].getResource() == "Wool") // צמר  מאדמת מרעה
                {
                    player.addResource("Wool", 1);
                }
            }
        }
    }

    return true;
}
// check if Edge has adjacent settlement or road
bool Board::hasAdjacentSettlementOrRoad(Vertex &first, Vertex &second, int playerNumber, Player &player)
{
    // Check if second is a neighbor of first and if it belongs to the player means he has city or settlement there.
    if (second.isNeighbor(first) && second.getOwner() == playerNumber)
    {
        return true;
    }
    // Check for adjacent settlement or road for the first vertex
    for (Vertex *neighbor1 : first.getNeighbors())
    {
        if (neighbor1->getOwner() == playerNumber)
        {
            return true; // Player owns a settlement or city adjacent to first vertex
        }
        // Check if there's a road adjacent to first vertex owned by the player
        if (hasRoad(first.getIndex(), neighbor1->getIndex(), playerNumber, player))
        {
            return true;
        }
    }

    // Check for adjacent settlement or road for the second vertex
    for (Vertex *neighbor2 : second.getNeighbors())
    {
        if (neighbor2->getOwner() == playerNumber)
        {
            return true; // Player owns a settlement or city adjacent to second vertex
        }
        // Check if there's a road adjacent to second vertex owned by the player
        if (hasRoad(second.getIndex(), neighbor2->getIndex(), playerNumber, player))
        {
            return true;
        }
    }

    // No adjacent settlement or road owned by the player found
    return false;
}

// Function to get the vertices connected by an edge
pair<size_t, size_t> Board::getVerticesFromEdge(int edgeIndex) const
{
    // Implement the logic to retrieve the vertices connected by the given edge index
    // This is a placeholder implementation and should be replaced with actual logic
    // Assuming that edges are stored as pairs of vertex indices in boardEdges
    return {boardEdges[edgeIndex].getVertex1()->getIndex(), boardEdges[edgeIndex].getVertex2()->getIndex()};
}

// Function to retrieve a vertex by its index
const Vertex &Board::getVertex(size_t index) const
{
    return boardVertices[index];
}

// Function to check if an edge is owned
bool Board::isEdgeOwned(int edgeIndex) const
{
    if (edgeIndex >= 0 && edgeIndex < boardEdges.size())
    {
        return boardEdges[edgeIndex].getOwner() != -1; // Check if edge has an owner
    }
    return false; // Edge index out of bounds or uninitialized edge
}

int Board::pathOfRoads(int playerNumber, Player &player)
{

    unordered_set<int> visitedEdges; // Set to track visited edges
    int longestPath = 0;

    // Function to perform DFS and count the connected roads
    function<int(int)> dfs = [&](int edgeIndex) -> int
    {
        stack<int> stack;
        stack.push(edgeIndex);
        visitedEdges.insert(edgeIndex);
        int pathLength = 0;

        while (!stack.empty())
        {
            int currentEdge = stack.top();
            stack.pop();
            ++pathLength;

            // Get the vertices connected by this edge
            auto [vertex1, vertex2] = getVerticesFromEdge(currentEdge);

            // Explore neighbors of both vertices
            for (size_t neighbor : {vertex1, vertex2})
            {
                const vector<Vertex *> &neighbors = getVertex(neighbor).getNeighbors();
                for (const Vertex *neighborVertex : neighbors)
                {
                    int neighborEdge = getEdge(neighbor, neighborVertex->getIndex());
                    if (visitedEdges.find(neighborEdge) == visitedEdges.end() &&
                        hasRoad(neighbor, neighborVertex->getIndex(), playerNumber, player))
                    {
                        visitedEdges.insert(neighborEdge);
                        stack.push(neighborEdge);
                    }
                }
            }
        }
        return pathLength;
    };

    // Iterate through all the roads owned by the player
    for (int road : player.getRoads())
    {
        if (visitedEdges.find(road) == visitedEdges.end())
        {
            longestPath = std::max(longestPath, dfs(road));
        }
    }

    return longestPath;
}
// check in in road vertex index the player has road.
bool Board::hasRoad(size_t vertex1, size_t vertex2, int playerNumber, Player &player) const
{
    bool playerHasAdjacentRoad = false;
    int edgeIndex = getEdge(vertex1, vertex2);

    for (int road : player.getRoads())
    {
        if (road == edgeIndex)
        {
            playerHasAdjacentRoad = true;
        }
    }
    return playerHasAdjacentRoad;
}
bool Board::checkHasAdjacentCityOrSettlement(const Vertex &vertex1, int playerNumber) const
{
    if (vertex1.getOwner() == playerNumber)
    {
        return true;
    }
    const vector<Vertex *> &neighbors = vertex1.getNeighbors();
    for (const Vertex *neighbor : neighbors)
    {
        if (neighbor->getOwner() == playerNumber)
        {
            return true;
        }
    }
    return false;
}

// verify there is path of 2 roads of player or empty vertex that aloud placing new settlement
bool Board::checkSettlementPlacement(int playerNumber, size_t vertexIndex)
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
        cerr << "Vertex is already occupied." << endl;
        return false;
    }

    // Check if the vertex the player wants to set as a settlement is adjacent to a vertex that is already occupied by one of the players
    const vector<Vertex *> &adjacentPlots = vertexForSettlement.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            cout << "Adjacent vertex " << adjacentVertex->getIndex() << " already occupied." << endl;
            return false;
        }
    }

    // Check for the presence of roads adjacent to the vertex
    bool hasAdjacentRoad = false;
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        int edgeIndex1 = getEdge(vertexIndex, adjacentVertex->getIndex());
        if (edgeIndex1 != -1 && boardEdges[edgeIndex1].getOwner() == playerNumber)
        {
            hasAdjacentRoad = true;
            break;
        }
    }

    // If there are no adjacent roads owned by the player, the settlement can be placed
    if (!hasAdjacentRoad)
    {
        return true;
    }

    // Check for two connected roads belonging to the player
    int playerRoadsCount = 0;
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        int edgeIndex1 = getEdge(vertexIndex, adjacentVertex->getIndex());
        if (edgeIndex1 != -1 && boardEdges[edgeIndex1].getOwner() == playerNumber)
        {
            playerRoadsCount++;
            for (const Vertex *furtherVertex : adjacentVertex->getNeighbors())
            {
                if (furtherVertex->getIndex() != vertexIndex)
                {
                    int edgeIndex2 = getEdge(adjacentVertex->getIndex(), furtherVertex->getIndex());
                    if (edgeIndex2 != -1 && boardEdges[edgeIndex2].getOwner() == playerNumber)
                    {
                        playerRoadsCount++;
                        if (playerRoadsCount == 2)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    cerr << "Player does not have a path of two connected roads to the vertex." << endl;
    return false;
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
    Vertex &vertex = boardVertices[vertexIndex];

    // Check if the vertex is already occupied by a city
    if (vertex.getOwner() != playerId)
    {
        cerr << "Vertex is not occupied by the player." << endl;
        return false;
    }

    // Check if the vertex is already occupied by a city
    if (vertex.getSettlement() == 1)
    {
        cerr << "Vertex is already occupied by a city." << endl;
        return false;
    }
    vertex.setSettlement(1);
    return true;
}
// New function to get a reference to the board tiles
vector<Tile> &Board::getBoardTiles()
{
    return boardTiles;
}

// return the int of edge location that built of the 2 vertices if the edge not exist return -1.
int Board::getEdge(size_t vertexIndex1, size_t vertexIndex2) const
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

void Board::upgradeSettlementToCity(size_t vertexIndex, Player &player)
{

    // Upgrade the settlement Vertex to a city equal to 2
    boardVertices[vertexIndex].setSettlement(2);
    // Update player's points for upgrading to a city
    player.add1point();
    player.addCity(vertexIndex);
    // update boardTiles at this vertex of this settlement of player.
    updateTileAtVertex(vertexIndex, player);
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

void Board::buildSettlement(size_t vertexIndex, Player &player)
{
    if (!player.canBuySettlement())
    {
        throw std::runtime_error("Player does not have enough resources to build a settlement.");
    }

    // Deduct the resources needed for a settlement
    player.removeResource("Lumber", 1);
    player.removeResource("Brick", 1);
    player.removeResource("Grain", 1);
    player.removeResource("Wool", 1);

    // Set the owner of the vertex to the player number
    boardVertices[vertexIndex].setOwner(player.getPlayerNumber());
    // set vertex-> settlement value to 1
    boardVertices[vertexIndex].setSettlement(1);
    // add 1 point for each settlement
    player.add1point();
    // add settlement to player settlements.
    player.addSettlement(vertexIndex);
    // update boardTiles at this vertex of this settlement of player.
    updateTileAtVertex(vertexIndex, player);
    // Assuming there's a method to set the owner on a vertex
    // vertexForSettlement.setOwner(player.getPlayerNumber())
}

void Board::buildRoad(size_t vertex1, size_t vertex2, Player &player)
{

    // Deduct the resources needed for a road
    player.removeResource("Brick", 1);
    player.removeResource("Lumber", 1);

    int edgeIndex = getEdge(vertex1, vertex2);
    if (edgeIndex == -1)
    {
        throw runtime_error("Invalid vertices for building a road.");
    }

    //  Set the owner of the edge to the player number
    boardEdges[edgeIndex].setOwner(player.getPlayerNumber());
    // Add road to player roads
    player.addRoad(edgeIndex);
}

void Board::buildRoadFree(Player &player)
{
    int vertexIndex1, vertexIndex2;
    cout << "Enter two vertex indices to place the road between: ";
    cin >> vertexIndex1 >> vertexIndex2;
    vector<Vertex> boardVertices1 = this->getBoardVertices();

    // Check if the vertex indices are valid
    if (!(vertexIndex1 >= 0 && vertexIndex1 < boardVertices1.size() &&
          vertexIndex2 >= 0 && vertexIndex2 < boardVertices1.size()))
    {
        cout << "Invalid vertex indices." << endl;
    }
    Vertex &vertex1 = boardVertices1[vertexIndex1];
    Vertex &vertex2 = boardVertices1[vertexIndex2];

    // Ensure vertices are neighbors
    if (!vertex1.isNeighbor(vertex2))
    {
        cout << "Vertices are not neighbors." << endl;
        return;
    }

    // Ensure there is an edge between these vertices
    int edgeIndex = this->getEdge(vertexIndex1, vertexIndex2);
    if (edgeIndex == -1)
    {
        cout << "No edge between these vertices." << endl;
        return;
    }
    Edge edge = Edge(edgeIndex);
    if (!edgeIndex)
    {
        cout << "No edge between these vertices." << endl;
        return;
    }
    // Check if the road is already owned
    if (edge.getOwner() != -1)
    {
        cout << "Road is already owned by a player." << endl;
        return;
    }
    // Check if the vertices are adjacent and if the player can build a road there
    if (this->hasAdjacentSettlementOrRoad(vertex1, vertex2, player.getPlayerNumber(), player))
    {
        int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
        if (edgeIndex == -1)
        {
            throw runtime_error("Invalid vertices for building a road.");
        }
        //  Set the owner of the edge to the player number
        boardEdges[edgeIndex].setOwner(player.getPlayerNumber());
        // Add road to player roads
        player.addRoad(edgeIndex);
    }
    else
    {
        cout << "Invalid placement. Please choose adjacent vertices with a settlement or road belonging to you." << endl;
        return;
    }

    cout << "Road successfully built between vertices " << vertexIndex1 << " and " << vertexIndex2 << "." << endl;
}

void Board::distribution(vector<Player *> &players, int diceRoll)
{
    if (diceRoll != 7)
    {
        for (int i = 0; i < 19; i++)
        {
            if (boardTiles[i].getNumber() == diceRoll)
            {
                const vector<Vertex *> &vertices = boardTiles[i].getVertices();
                for (Vertex *vertex : vertices)
                {
                    // Find the corresponding vertex in boardVertices
                    for (Vertex &boardVertex : boardVertices)
                    {
                        if (boardVertex.getIndex() == vertex->getIndex())
                        {
                            // Perform resource distribution based on boardVertex and boardTiles[i]
                            if (vertex->getOwner() != -1 && vertex->getSettlement() > 0)
                            {
                                distributeResources(players, boardVertex, boardTiles[i], vertex->getSettlement());
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Board::distributeResources(vector<Player *> &players, const Vertex &vertex, const Tile &tile, int settlementLevel)
{
    int playerId = vertex.getOwner();

    // Check the resource type and add to player's resources based on settlement level
    if (tile.getResource() == "Brick")
    {
        players[playerId]->addResource("Brick", settlementLevel);
    }
    else if (tile.getResource() == "Grain")
    {
        players[playerId]->addResource("Grain", settlementLevel);
    }
    else if (tile.getResource() == "Lumber")
    {
        players[playerId]->addResource("Lumber", settlementLevel);
    }
    else if (tile.getResource() == "Ore")
    {
        players[playerId]->addResource("Ore", settlementLevel);
    }
    else if (tile.getResource() == "Wool")
    {
        players[playerId]->addResource("Wool", settlementLevel);
    }
}

// Function to update the tile at a specific vertex based on the player's action on board vertices
void Board::updateTileAtVertex(size_t vertexIndex, Player &player)
{
    // Check if the vertex index is valid
    if (vertexIndex >= 0 && vertexIndex < boardVertices.size())
    {
        // Check if the vertex has a settlement or city of the player
        if (boardVertices[vertexIndex].getOwner() == player.getPlayerNumber() &&
            (boardVertices[vertexIndex].getSettlement() == 1 || boardVertices[vertexIndex].getSettlement() == 2))
        {
            // Iterate through all tiles to find the tile containing the vertex
            for (Tile &tile : boardTiles)
            {
                // Check if the tile has the specific vertex
                for (Vertex *vertex : tile.getVertices())
                {
                    if (vertex->getIndex() == vertexIndex)
                    {
                        // Update the tile's owner and settlement using the tile reference
                        vertex->setOwner(player.getPlayerNumber());
                        vertex->setSettlement(boardVertices[vertexIndex].getSettlement());
                        // Exit the loop once the tile is updated
                        break;
                    }
                }
            }
        }
        else
        {
            std::cout << "Error: Player does not have a settlement or city at vertex " << vertexIndex << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Invalid vertex index " << vertexIndex << std::endl;
    }
}