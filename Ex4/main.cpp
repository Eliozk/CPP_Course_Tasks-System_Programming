// Mail: kolanielioz@gmail.com 
#include <iostream>
#include <string>
#include "Tree.hpp"

using namespace std;

int main() {
  
    Tree<double> tree; // Binary tree that contains doubles.

    Node<double> root_node(1.1);
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    std::cout << "Double tree of K=2 Pre-Order: ";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    std::cout << endl;

    std::cout << "Double tree of K=2 Post-Order: ";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
        std::cout << endl;
    std::cout << "Double tree of K=2 In-Order: ";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << endl;

    std::cout << "Double tree of K=2 BFS: ";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << endl;

    std::cout << "Double tree print of K=2 DFS: ";
    for(auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node){
        cout << node->get_value() << " ";
    }
    std::cout << endl;

    std::cout << "Printing tree by nodes of the tree - should be like BFS: ";
    for (auto node : tree) {
        cout << node->get_value() << " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << endl;

     std::cout << "Heap order traversal: ";
    for (auto node = tree.begin_heap_order(); node != tree.end_heap_order(); ++node) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

     tree.print();// Should print the graph using GUI.


/**
 * Tree<double> tree; // Binary tree that contains doubles.
    
    Node<double> root_node(1.1);
    tree.add_root(root_node); */ 
    
 // Example usage of Tree with Complex number type and 3-ary structure (K=3)
    Tree<Complex, 3> complex_tree3;

      // Create nodes with Complex values
    Node<Complex> c_root_node(Complex(1.1, 2.2));
    Node<Complex> c_n1(Complex(3.3, 4.4));
    Node<Complex> c_n2(Complex(5.5, 6.6));
    Node<Complex> c_n3(Complex(7.7, 8.8));
    Node<Complex> c_n4(Complex(9.9, 10.1));
    Node<Complex> c_n5(Complex(11.1, 12.2));

    // Build the complex tree structure
    complex_tree3.add_root(c_root_node);
    complex_tree3.add_sub_node(c_root_node, c_n1);
    complex_tree3.add_sub_node(c_root_node, c_n2);
    complex_tree3.add_sub_node(c_root_node, c_n3);
    complex_tree3.add_sub_node(c_n1, c_n4);
    complex_tree3.add_sub_node(c_n2, c_n5);

    // Print pre-order traversal of complex tree
    cout << "\nThree-ary tree of K=3 Pre-Order: ";
    for (auto node = complex_tree3.begin_pre_order(); node != complex_tree3.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Print post-order traversal of complex tree
    cout << "Three-ary tree of K=3 Post-Order: ";
    for (auto node = complex_tree3.begin_post_order(); node != complex_tree3.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Print in-order traversal of complex tree
    cout << "Three-ary tree of K=3 In-Order: ";
    for (auto node = complex_tree3.begin_in_order(); node != complex_tree3.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Print DFS traversal of complex tree
    cout << "Three-ary tree print of K=3 DFS: ";
    for (auto node = complex_tree3.begin_dfs_scan(); node != complex_tree3.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Print BFS traversal of complex tree
    cout << "Three-ary tree of K=3 BFS: ";
    for (auto node = complex_tree3.begin_bfs_scan(); node != complex_tree3.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Print using range-based loop (should be same as BFS) for complex tree
    cout <<"Printing tree by nodes of the tree - should be like BFS: ";
    for (auto node : complex_tree3) {
        cout << node->get_value() << " ";
    }
    cout << endl;

   complex_tree3.print();
}
