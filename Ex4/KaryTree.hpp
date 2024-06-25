#ifndef KARYTREE_HPP
#define KARYTREE_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <cxxabi.h> // Include for demangling
using namespace std;

//type of key T and number of childs k(max)  k here is for the defauld constructor(k=2)
template <typename T, size_t K = 2>
class KaryTree {
private:
//struct node for the tree each Node has generic key and vector of ptr's nodes.
    struct Node {
        T key;
        std::vector<Node*> children;
        Node(const T& key) : key(key) {}
        
    };
    //members of the tree(node and size as max children for kary tree).
    Node* root;
    size_t maxChildren;
    
    void deleteNode(Node* node);

public:
    // Default constructor for a binary tree k=2 defined in top of the file.
    KaryTree();
    // Constructor for a K-ary tree
    KaryTree(size_t k);

    ~KaryTree();

    void setRoot(const T& key);

    bool addChild(const T& parentKey, const T& childKey);

    Node* findNode(Node* node, const T& key);

    // DFS Iterator
    class Iterator {
    private:
        Node* current;
        stack<Node*> nodesStack;

    public:
        Iterator(Node* root);

        void advance();

        T& operator*();
        Iterator& operator++();

        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
    private:
    
};

#include "KaryTree.tpp"

#endif // KARYTREE_HPP
