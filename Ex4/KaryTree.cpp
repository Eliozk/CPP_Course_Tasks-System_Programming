#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T>
class Tree {
private:
    struct Node {
        T value;
        vector<unique_ptr<Node>> children;
        Node(T val, size_t maxChildren) : value(val), children(maxChildren) {}
    };
    std::unique_ptr<Node> root;
    size_t maxChildren;

    void preOrderTraversal(Node* node, vector<T>& result) const {
        if (!node) return;
        result.push_back(node->value);
        for (auto& child : node->children) {
            preOrderTraversal(child.get(), result);
        }
    }

    void postOrderTraversal(Node* node, std::vector<T>& result) const {
        if (!node) return;
        for (auto& child : node->children) {
            postOrderTraversal(child.get(), result);
        }
        result.push_back(node->value);
    }

    // void inOrderTraversal(Node* node, vector<T>& result) const {
    //     if (!node || maxChildren != 2) return; // Only for binary tree
    //     if (node->children[0]) inOrderTraversal(node->children[0].get(), result);
    //     result.push_back(node->value);
    //     if (node->children[1]) inOrderTraversal(node->children[1].get(), result);
    // }

void inOrderTraversal(Node* node, vector<T>& result) const {
    if (!node) return; // Base case: nullptr check

    // Traverse left subtree
    if (node->children.size() > 0) {
        inOrderTraversal(node->children[0].get(), result);
    }
    // Process current node
    result.push_back(node->value);
    // Traverse right subtree
    // Note: Traverse all children in the right subtree
    for (size_t i = 1; i < node->children.size(); ++i) {
        inOrderTraversal(node->children[i].get(), result);
    }
}




public:
    Tree(size_t k = 2) : maxChildren(k) {}

    void add_root(T val) {
        root = make_unique<Node>(val, maxChildren);
    }

    void add_sub_node(T parentVal, T childVal) {
    // If the tree is empty, throw an exception
    if (!root) throw runtime_error("Tree is empty");

    // Queue to store nodes for processing
    queue<Node*> nodes;
    
    // Push the root node to the queue
    nodes.push(root.get());
    
    // Loop as long as there are nodes in the queue
    while (!nodes.empty()) {
        // Get the first node in the queue
        Node* node = nodes.front();
        nodes.pop();

        // If the value of the current node is equal to the parent value
        if (node->value == parentVal) {
            // Iterate over all children of the current node
            for (auto& child : node->children) {
                // If there is an empty slot (child is not existing)
                if (!child) {
                    // Create a new node and place it in the empty slot
                    child = make_unique<Node>(childVal, maxChildren);
                    return; // End the function
                }
            }
            // If there is no empty slot (all slots are occupied), throw an exception
            throw runtime_error("No empty child slot available");
        }
        
        // If the value of the current node is not equal to the parent value,
        // push its children to the queue for further processing
        for (auto& child : node->children) {
            if (child) nodes.push(child.get());
        }
    }

    // If no node with the parent value is found, throw an exception
    throw std::runtime_error("Parent node not found");
}


    std::vector<T> begin_pre_order() const {
        vector<T> result;
        preOrderTraversal(root.get(), result);
        return result;
    }

    std::vector<T> end_pre_order() const {
        return {};
    }

    vector<T> begin_post_order() const {
        std::vector<T> result;
        postOrderTraversal(root.get(), result);
        return result;
    }

    vector<T> end_post_order() const {
        return {};
    }

    std::vector<T> begin_in_order() const {
        vector<T> result;
        inOrderTraversal(root.get(), result);
        return result;
    }

    std::vector<T> end_in_order() const {
        return {};
    }

    std::vector<T> begin_bfs_scan() const {
        std::vector<T> result;
        if (!root) return result;
        std::queue<Node*> nodes;
        nodes.push(root.get());
        while (!nodes.empty()) {
            Node* node = nodes.front();
            nodes.pop();
            result.push_back(node->value);
            for (auto& child : node->children) {
                if (child) nodes.push(child.get());
            }
        }
        return result;
    }

    std::vector<T> end_bfs_scan() const {
        return {};
    }

    std::vector<T> begin_dfs_scan() const {
        std::vector<T> result;
        if (!root) return result;
        std::stack<Node*> nodes;
        nodes.push(root.get());
        while (!nodes.empty()) {
            Node* node = nodes.top();
            nodes.pop();
            result.push_back(node->value);
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it) nodes.push(it->get());
            }
        }
        return result;
    }

    std::vector<T> end_dfs_scan() const {
        return {};
    }

    std::vector<T> myHeap() {
        std::vector<T> result = begin_pre_order();
        std::make_heap(result.begin(), result.end(), std::greater<T>());
        return result;
    }
};

// In KaryTree.hpp or KaryTree.cpp

// In KaryTree.hpp or KaryTree.cpp

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



