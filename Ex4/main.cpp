#include "KaryTree.hpp"
#include <string>
using namespace std;

int main() {
    KaryTree<string> binaryTree; // Default binary tree
    binaryTree.setRoot("root");
    binaryTree.addChild("root", "child1");
    binaryTree.addChild("root", "child2");
    binaryTree.addChild("root", "child3");
    binaryTree.addChild("child1", "grandchild1");

    cout << "Binary Tree:" << std::endl;
    for (auto it = binaryTree.begin(); it != binaryTree.end(); ++it) {
        cout << *it << " ";
    }
    std::cout << std::endl;

    KaryTree<string, 3> ternaryTree; // K-ary tree with K=3
    ternaryTree.setRoot("root");
    ternaryTree.addChild("root", "child1");
    ternaryTree.addChild("root", "child2");
    ternaryTree.addChild("root", "child3");
    ternaryTree.addChild("child1", "grandchild1");

    std::cout << "Ternary Tree:" << std::endl;
    for (auto it = ternaryTree.begin(); it != ternaryTree.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

