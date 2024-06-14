// ID - 208762765
// GMAIL - kolanielioz@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace ariel;
using namespace std;


//*************************************************************************************************************************************8
TEST_CASE("Graph Operations")
{
    SUBCASE("Graph Addition and Subtraction")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 =
            {{0, 1, -2},
             {1, 0, 1},
             {-2, 1, 0}};
        vector<vector<int>> graph3 =
            {{0, 2, -3},
             {2, 0, 2},
             {-3, 2, 0}};
        vector<vector<int>> graph4 =
            {{0, 0, -1},
             {0, 0, 0},
             {-1, 0, 0}};
             vector<vector<int>> graph5 =
             {{0, 1},
             {1,  0},};

             vector<vector<int>> graph6 =
             {{0, 2},
             {2,  0},};
                  vector<vector<int>> graph1FromDemo = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
         vector<vector<int>> sameGraph1FromDemo = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
        Graph g1, g2, g3, g4,g5,g6,g7,g8;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        g3.loadGraph(graph3);
        g4.loadGraph(graph4);
        g5.loadGraph(graph5);
        g6.loadGraph(graph6);
        g7.loadGraph(graph1FromDemo);
        g8.loadGraph(sameGraph1FromDemo);
        g7--;
        g7++;
        CHECK( g7 != g8); // check ++ and -- and != operator at once for graph from demo.

        CHECK(g5 != g6);
        Graph sum = g1 + g2;
        Graph diff = g2 - g1;

        CHECK(sum == g3);
        CHECK(diff == g4);
        CHECK_FALSE(diff == g3);
    }

    SUBCASE("Graph Multiplication and >=")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 = {
            {0, 1, -2},
            {1, 0, 1},
            {-2, 1, 0}};
             vector<vector<int>> graph3 =
             {{3, -1, 1}, 
             {-2, 2, -2}, 
             {1, -1, 3}};
             vector<vector<int>> graph4 =
             {{-3, 1, -1}, 
             {2, -2, 2}, 
             {-1, 1, -3}};
        Graph g1, g2,res,g4;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        res.loadGraph(graph3);
        g4.loadGraph(graph4);
         -g4;//unary minus
          Graph product = g1 * g2;
        CHECK(g4 == res);
        CHECK(product >= res);
    }

    SUBCASE("Unary Operators")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        Graph g;
        g.loadGraph(graph1);

        +g;
        -g;

        CHECK(g.getAdjacencyMatrix() == vector<vector<int>>{{0, -1, 1}, {-1, 0, -1}, {1, -1, 0}});
    }

    SUBCASE("Increment and Decrement Operators")
    {
        vector<vector<int>> graph = {
            {0, 2, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph1 = {
            {0, 2, -1},
            {1, 0, 1},
            {-1, 1, 0}};
             vector<vector<int>> graph2= {
            {0, 2, -2},
            {2, 0, 2},
            {-2, 2, 0}};
        Graph g,g1,g2;
        g.loadGraph(graph);
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        ++g1;
        --g1;
        ++g2;
        --g2;

        CHECK(!(g == g1));//check == operator and --, and ++
        CHECK(g2.getAdjacencyMatrix() == graph2);
    }

    SUBCASE("Graph Comparison")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 = {
            {0, 1, -2},
            {1, 0, 1},
            {-2, 1, 0}};
            vector<vector<int>> subGraph1 = {
            {0, 1, -1},
            {0, 0, 1},
            {-1, 1, 0}};
        Graph g1, g2,subg1;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        subg1.loadGraph(subGraph1);

        CHECK(g1 == g1);
        CHECK(g1 != g2);
        CHECK_FALSE(subg1 > g1);
        CHECK(g1 > subg1);
        CHECK(g1 <= g2);
        CHECK_FALSE(subg1 >= g1);
        
    }
}
