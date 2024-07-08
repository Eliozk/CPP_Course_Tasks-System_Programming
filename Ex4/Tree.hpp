// Mail: kolanielioz@gmail.com 

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


// Generic template for converting any type to a string
template <typename T>
std::string to_string(const T& value) {
    std::ostringstream transfer;
    transfer << value;
    return transfer.str();
}

// Specialization for std::string (std::__cxx11::basic_string<char>)
template <>
std::string to_string(const std::__cxx11::basic_string<char>& value) {
    return value; // Directly return the string
}



// Complex class representing complex numbers
class Complex {
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


    bool operator<(const Complex& other) const {
        return real < other.real || (real == other.real && imag < other.imag);
    }

    bool operator>(const Complex& other) const {
        return real > other.real || (real == other.real && imag > other.imag);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << "+" << c.imag << "i";
        return os;
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
};
// Node class representing node inside tree that have vecctor of nodes(childrens).
template <typename T>
class Node {
public:
    T data;
    std::vector<Node*> children;

    Node(const T& value) : data(value) {}

    T get_value() const {
        return data;
    }
};

//Struct Heap-Comparator helper to set priority queue as min heap.
template<typename T>
struct HeapComparator {
    bool operator()(const Node<T>* leftNode, const Node<T>* rightNode) const {
 // Comparing node data to maintain min-heap order   
      return leftNode->data > rightNode->data;  
    }
};


template <typename T, int K = 2>
class Tree {
public:
    class Iterator;

    Tree();
    ~Tree();
    void add_root(Node<T>& value);
    void add_sub_node(const Node<T>& parent_value, const Node<T>& child_value);

    Iterator begin_pre_order() const;
    Iterator end_pre_order() const;
    Iterator begin_post_order() const;
    Iterator end_post_order() const;
    Iterator begin_in_order() const;
    Iterator end_in_order() const;
    Iterator begin_bfs_scan() const;
    Iterator end_bfs_scan() const;
    Iterator begin_dfs_scan() const;
    Iterator end_dfs_scan() const;
    Iterator begin_heap_order() const;
    Iterator end_heap_order() const;
    void myHeap(Node<T>* node, std::vector<Node<T>*>& result) const;
    Iterator begin() const; // BFS by default
    Iterator end() const;

     void print() const;

private:
    Node<T>* root;
    int max_children;
    void destroy(Node<T>* node);
    Node<T>* find_node(Node<T>* node, const T& value) const; // Ensure this declaration matches the definition

    void pre_order(Node<T>* node, std::vector<Node<T>*>& result) const;
    void post_order(Node<T>* node, std::vector<Node<T>*>& result) const;
    void in_order(Node<T>* node, std::vector<Node<T>*>& result) const;
    void bfs_scan(Node<T>* node, std::vector<Node<T>*>& result) const;
    void DFS_scan(Node<T>* node, std::vector<Node<T>*>& result) const;
    
    void draw_tree(sf::RenderWindow& window, Node<T>* node, float x, float y, float x_offset, float y_offset) const; // Declare the draw_tree method here

public:
    class Iterator : public std::iterator<std::input_iterator_tag, Node<T>> {
        std::vector<Node<T>*> nodes;
        size_t index;
    public:
        Iterator(const std::vector<Node<T>*>& nodes, size_t idx);
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
        Node<T>* operator*() const;
        Node<T>* operator->() const; // operator-> to access the underlying pointer
    };
};

#include "Tree.tpp" // Include the template implementation

#endif // TREE_HPP
