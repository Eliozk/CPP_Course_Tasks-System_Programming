#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory>

template <typename T>
class Tree {
public:
    class Node {
    public:
        T value;
        std::vector<std::shared_ptr<Node>> children;
        
        Node(const T& val) : value(val), children() {}
    };

private:
    std::shared_ptr<Node> root;
    int max_children;

public:
    Tree(int k = 2) : root(nullptr), max_children(k) {}
    
    void add_root(const T& value) {
        if (!root) {
            root = std::make_shared<Node>(value);
        } else {
            root->value = value;
        }
    }

    bool add_sub_node(const T& parent_value, const T& child_value) {
        auto parent = find_node(root, parent_value);
        if (parent && parent->children.size() < max_children) {
            parent->children.push_back(std::make_shared<Node>(child_value));
            return true;
        }
        return false;
    }

    // Iterator classes and their functions
    class PreOrderIterator {
    private:
        std::stack<std::shared_ptr<Node>> stack;

    public:
        PreOrderIterator(std::shared_ptr<Node> root) {
            if (root) {
                stack.push(root);
            }
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        PreOrderIterator& operator++() {
            if (!stack.empty()) {
                auto node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }

        T& operator*() {
            return stack.top()->value;
        }
    };

    PreOrderIterator begin_pre_order() {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order() {
        return PreOrderIterator(nullptr);
    }

    class PostOrderIterator {
    private:
        std::stack<std::shared_ptr<Node>> stack;
        std::shared_ptr<Node> last;

        void push_all_left(std::shared_ptr<Node> node) {
            while (node) {
                stack.push(node);
                if (!node->children.empty()) {
                    node = node->children.front();
                } else {
                    node = nullptr;
                }
            }
        }

    public:
        PostOrderIterator(std::shared_ptr<Node> root) : last(nullptr) {
            push_all_left(root);
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        PostOrderIterator& operator++() {
            if (!stack.empty()) {
                auto node = stack.top();
                stack.pop();
                if (!stack.empty() && !stack.top()->children.empty() && stack.top()->children.back() == node) {
                    auto parent = stack.top();
                    stack.pop();
                    stack.push(node);
                    push_all_left(parent->children.back());
                }
                last = node;
            }
            return *this;
        }

        T& operator*() {
            return stack.top()->value;
        }
    };

    PostOrderIterator begin_post_order() {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() {
        return PostOrderIterator(nullptr);
    }

    class InOrderIterator {
    private:
        std::stack<std::shared_ptr<Node>> stack;
        std::shared_ptr<Node> current;

    public:
        InOrderIterator(std::shared_ptr<Node> root) : current(root) {
            while (current) {
                stack.push(current);
                current = (current->children.size() > 0) ? current->children[0] : nullptr;
            }
        }

        bool operator!=(const InOrderIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        InOrderIterator& operator++() {
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();
                if (current->children.size() > 1) {
                    current = current->children[1];
                    while (current) {
                        stack.push(current);
                        current = (current->children.size() > 0) ? current->children[0] : nullptr;
                    }
                } else {
                    current = nullptr;
                }
            }
            return *this;
        }

        T& operator*() {
            return stack.top()->value;
        }
    };

    InOrderIterator begin_in_order() {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() {
        return InOrderIterator(nullptr);
    }

    class BFSIterator {
    private:
        std::queue<std::shared_ptr<Node>> queue;

    public:
        BFSIterator(std::shared_ptr<Node> root) {
            if (root) {
                queue.push(root);
            }
        }

        bool operator!=(const BFSIterator& other) const {
            return !queue.empty() || !other.queue.empty();
        }

        BFSIterator& operator++() {
            if (!queue.empty()) {
                auto node = queue.front();
                queue.pop();
                for (auto& child : node->children) {
                    queue.push(child);
                }
            }
            return *this;
        }

        T& operator*() {
            return queue.front()->value;
        }
    };

    BFSIterator begin_bfs_scan() {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() {
        return BFSIterator(nullptr);
    }

    class DFSIterator {
    private:
        std::stack<std::shared_ptr<Node>> stack;

    public:
        DFSIterator(std::shared_ptr<Node> root) {
            if (root) {
                stack.push(root);
            }
        }

        bool operator!=(const DFSIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        DFSIterator& operator++() {
            if (!stack.empty()) {
                auto node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }

        T& operator*() {
            return stack.top()->value;
        }
    };

    DFSIterator begin_dfs_scan() {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() {
        return DFSIterator(nullptr);
    }

    class MinHeapIterator {
    private:
        std::vector<std::shared_ptr<Node>> heap;
        size_t index;

        void build_min_heap() {
            for (size_t i = heap.size() / 2; i > 0; --i) {
                heapify(i - 1);
            }
        }

        void heapify(size_t i) {
            size_t smallest = i;
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < heap.size() && heap[left]->value < heap[smallest]->value) {
                smallest = left;
            }

            if (right < heap.size() && heap[right]->value < heap[smallest]->value) {
                smallest = right;
            }

            if (smallest != i) {
                std::swap(heap[i], heap[smallest]);
                heapify(smallest);
            }
        }

    public:
        MinHeapIterator(std::shared_ptr<Node> root) : index(0) {
            fill_heap(root);
            build_min_heap();
        }

        void fill_heap(std::shared_ptr<Node> node) {
            if (node) {
                heap.push_back(node);
                for (auto& child : node->children) {
                    fill_heap(child);
                }
            }
        }

        bool operator!=(const MinHeapIterator& other) const {
            return index != other.index;
        }

        MinHeapIterator& operator++() {
            if (index < heap.size()) {
                ++index;
            }
            return *this;
        }

        T& operator*() {
            return heap[index]->value;
        }
    };

    MinHeapIterator myHeap() {
        return MinHeapIterator(root);
    }

private:
    std::shared_ptr<Node> find_node(std::shared_ptr<Node> current, const T& value) {
        if (!current) {
            return nullptr;
        }
        if (current->value == value) {
            return current;
        }
        for (auto& child : current->children) {
            auto result = find_node(child, value);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }
};

#endif // TREE_HPP
