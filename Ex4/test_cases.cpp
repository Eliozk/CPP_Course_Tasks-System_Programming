// Mail: kolanielioz@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"

TEST_CASE("Binary Tree Operations")
{
    Tree<int> tree;

    Node<int> root_node(1);
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    
    SUBCASE("Pre-Order Traversal")
    {
        std::vector<Node<int> *> expected_pre_order = {&root_node, &n1, &n3, &n4, &n2, &n5};//1,2,4,5,3,6
        auto it = tree.begin_pre_order();
        for (auto expected_node : expected_pre_order)
        {
            CHECK((*it)->get_value() == expected_node->get_value());
            ++it;
        }
        // REQUIRE(it == tree.end_pre_order());
    }

    SUBCASE("Post-Order Traversal")
    {
        std::vector<Node<int> *> expected_post_order = {&n3, &n4, &n1, &n5, &n2, &root_node};//4,5,2,6,3,1
        auto it = tree.begin_post_order();
        for (auto expected_node : expected_post_order)
        {
            CHECK((*it)->get_value() == expected_node->get_value());
            ++it;
        }
        // REQUIRE(it == tree.end_post_order());
    }

    SUBCASE("Post-Order Traversal")
    {
        std::vector<Node<int> *> expected_in_order = {&n3, &n1, &n4, &root_node, &n5, &n2};//4,2,5,1,6,3
        auto it = tree.begin_in_order();
        for (auto expected_node : expected_in_order)
        {
            CHECK((*it)->get_value() == expected_node->get_value());
            ++it;
        }
    }
}


TEST_CASE("Complex Tree Operations")
{
    Tree<double, 3> complex_tree3;

    Node<double> c_root_node(1.1);
    Node<double> c_n1(2.2);
    Node<double> c_n2(3.3);
    Node<double> c_n3(4.4);
    Node<double> c_n4(5.5);
    Node<double> c_n5(6.6);

    complex_tree3.add_root(c_root_node);
    complex_tree3.add_sub_node(c_root_node, c_n1);
    complex_tree3.add_sub_node(c_root_node, c_n2);
    complex_tree3.add_sub_node(c_root_node, c_n3);
    complex_tree3.add_sub_node(c_n1, c_n4);
    complex_tree3.add_sub_node(c_n2, c_n5);
      
    SUBCASE("Pre-Order Traversal")
    {
        std::vector<Node<double> *> expected_pre_order = {&c_root_node, &c_n1, &c_n4, &c_n2, &c_n5, &c_n3};
        auto it = complex_tree3.begin_pre_order();
        for (auto expected_node : expected_pre_order)
        {
            CHECK((*it)->get_value() == expected_node->get_value());
            ++it;
        }
        // REQUIRE(it == complex_tree3.end_pre_order());
    }

    SUBCASE("Post-Order Traversal")
    {
        std::vector<Node<double> *> expected_post_order = {&c_root_node, &c_n1, &c_n4, &c_n2, &c_n5, &c_n3};
        auto it = complex_tree3.begin_post_order();
        for (auto expected_node : expected_post_order)
        {
            CHECK((*it)->get_value() == expected_node->get_value());
            ++it;
        }
        // REQUIRE(it == complex_tree3.end_post_order());
    }
}
