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
std::string to_string(const T &value)
{
    std::ostringstream transfer;
    transfer << value;
    return transfer.str();
}

// Specialization for std::string (std::__cxx11::basic_string<char>)
template <>
std::string to_string(const std::__cxx11::basic_string<char> &value)
{
    return value; // Directly return the string
}

// Complex class representing complex numbers
class Complex
{
public:
    double real, imag; // the real and imaginary values of the complex number.
    /**
     * @brief Constructor to initialize a complex number.
     * @param r The real part of the complex number. Default is 0.0.
     * @param i The imaginary part of the complex number. Default is 0.0.
     */
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Less-than operator to compare two complex numbers.
    bool operator<(const Complex &other) const
    {
        return real < other.real || (real == other.real && imag < other.imag);
    }
    // Greater-than operator to compare two complex numbers.
    bool operator>(const Complex &other) const
    {
        return real > other.real || (real == other.real && imag > other.imag);
    }
    /**
     * @brief Output stream operator to print a complex number.
     * @param os The output stream.
     * @param c The complex number to print.
     * @return The output stream with the complex number in the format "real+imagi".
     */
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
    // Equality operator to check if two complex numbers are equal.
    bool operator==(const Complex &other) const
    {
        return real == other.real && imag == other.imag;
    }
};
// Node class representing node inside tree that have vecctor of nodes(childrens).
template <typename T>
class Node
{
public:
    T data;                       //< The data stored in the node.
    std::vector<Node *> children; //< A vector of pointers to the node's children.
    /**
     * @brief Constructor to initialize a node with a given value.
     * @param value The value to be stored in the node.
     */
    Node(const T &value) : data(value) {}
    /**
     * @brief Get the value stored in the node.
     * @return The value stored in the node.
     */
    T get_value() const
    {
        return data;
    }
};

// Struct Heap-Comparator helper to set priority queue as min heap.
template <typename T>
struct HeapComparator
{
    bool operator()(const Node<T> *leftNode, const Node<T> *rightNode) const
    {
        // Comparing node data to maintain min-heap order
        return leftNode->data > rightNode->data;
    }
};

// Template class Tree
template <typename T, int K = 2>
class Tree
{
public:
    class Iterator;

    Tree();
    ~Tree();
    void add_root(Node<T> &value);
    void add_sub_node(const Node<T> &parent_value, const Node<T> &child_value);

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
    void myHeap(Node<T> *node, std::vector<Node<T> *> &result) const;
    Iterator begin() const; // BFS by default
    Iterator end() const;

    void print() const;

private:
    Node<T> *root;
    int max_children;
    void destroy(Node<T> *node);
    Node<T> *find_node(Node<T> *node, const T &value) const;

    void pre_order(Node<T> *node, std::vector<Node<T> *> &result) const;
    void post_order(Node<T> *node, std::vector<Node<T> *> &result) const;
    void in_order(Node<T> *node, std::vector<Node<T> *> &result) const;
    void bfs_scan(Node<T> *node, std::vector<Node<T> *> &result) const;
    void DFS_scan(Node<T> *node, std::vector<Node<T> *> &result) const;

    void draw_tree(sf::RenderWindow &window, Node<T> *node, float x, float y, float x_offset, float y_offset) const; // Declare the draw_tree method here

public:
    /**
     * @class Iterator
     * @brief An iterator class to traverse the tree.
     * This nested class allows the Tree class to provide various traversal mechanisms
     * (pre-order, post-order, in-order, BFS, DFS, heap order) through its public methods.
     */
    // std::iterator: This is a class template in the standard library that provides basic functionalities for iterators.
    //<std::input_iterator_tag, Node<T>>:
    // std::input_iterator_tag: This specifies the category of the iterator, indicating that Iterator is an input iterator. Input iterators allow read-only access to a sequence of elements.
    // Node<T>: This specifies the type of elements that the iterator will point to. In this case, Iterator will iterate over nodes of type Node<T>
   //ספרייה מובנית של איטרטורים מוגדרת כאינפוט מקבלת קלט לביצוע משימות ומגדירה סוג איברים שהאיטרטור יצביע עליהם
    class Iterator : public std::iterator<std::input_iterator_tag, Node<T>>
    {
        std::vector<Node<T> *> nodes; //< A vector to store nodes in traversal order.
        size_t index;                 //< Current index in the traversal.
    public:
        /**
         * @brief Constructor to initialize the iterator.
         * @param nodes A vector of nodes to traverse.
         * @param idx The starting index for the traversal.
         */
        Iterator(const std::vector<Node<T> *> &nodes, size_t idx);
        /**
         * @brief Pre-increment operator to advance the iterator.
         * @return A reference to the advanced iterator.
         */
        Iterator &operator++();

        /**
         * @brief Inequality operator to compare iterators.
         * @param other The other iterator to compare against.
         * @return True if the iterators are not equal, false otherwise.
         */
        bool operator!=(const Iterator &other) const;
        /**
         * @brief Dereference operator to access the current node.
         * @return A pointer to the current node.
         */
        Node<T> *operator*() const;
        /**
         * @brief Arrow operator to access the underlying pointer.
         * @return A pointer to the current node.
         */
        Node<T> *operator->() const; // operator-> to access the underlying pointer
    };
};

#include "Tree.tpp" // Include the template implementation

#endif // TREE_HPP
