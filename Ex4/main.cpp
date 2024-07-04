#include <iostream>
#include "KaryTree.cpp"  // הכנס כאן את כל הקוד של המחלקה Tree



int main() {
    // עץ של מספרים שלמים עם 3 ילדים מקסימליים לכל צומת
    Tree<int> int_tree(3);
    int_tree.add_root(1);
    int_tree.add_sub_node(1, 2);
    int_tree.add_sub_node(1, 3);
    int_tree.add_sub_node(1, 4);
    int_tree.add_sub_node(2, 5);
    int_tree.add_sub_node(2, 6);
    int_tree.add_sub_node(3, 7);

    std::cout << "Integer Tree Pre-Order: ";
    for (const auto& val : int_tree.begin_pre_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Integer Tree Post-Order: ";
    for (const auto& val : int_tree.begin_post_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Integer Tree In-Order: ";
    for (const auto& val : int_tree.begin_in_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Integer Tree BFS: ";
    for (const auto& val : int_tree.begin_bfs_scan()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Integer Tree DFS: ";
    for (const auto& val : int_tree.begin_dfs_scan()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Integer Tree Min-Heap: ";
    auto heap = int_tree.myHeap();
    for (const auto& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // עץ של מספרים מרוכבים עם 2 ילדים מקסימליים לכל צומת
    Tree<Complex> complex_tree(2); // עץ בינארי עם מספרים מרוכבים
    complex_tree.add_root(Complex(1.0, 2.0));
    complex_tree.add_sub_node(Complex(1.0, 2.0), Complex(3.0, 4.0));
    complex_tree.add_sub_node(Complex(1.0, 2.0), Complex(5.0, 6.0));

    std::cout << "Complex Tree Pre-Order: ";
    for (const auto& val : complex_tree.begin_pre_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Tree Post-Order: ";
    for (const auto& val : complex_tree.begin_post_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Tree In-Order: ";
    for (const auto& val : complex_tree.begin_in_order()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Tree BFS: ";
    for (const auto& val : complex_tree.begin_bfs_scan()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Tree DFS: ";
    for (const auto& val : complex_tree.begin_dfs_scan()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex Tree Min-Heap: ";
    auto complex_heap = complex_tree.myHeap();
    for (const auto& val : complex_heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
