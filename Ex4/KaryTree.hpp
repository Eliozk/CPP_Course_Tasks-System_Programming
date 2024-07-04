

//איטרטורים לשנות
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename Key>
class Tree {
private:
    struct Node {
        Key key;
        vector<unique_ptr<Node>> children;
        Node(const Key& k, size_t maxChildren) : key(k), children(maxChildren) {}
    };
    unique_ptr<Node> root;
    size_t maxChildren;

    void preOrderTraversal(Node* node, vector<Key>& result) const {
        if (!node) return;
        result.push_back(node->key);
        for (auto& child : node->children) {
            preOrderTraversal(child.get(), result);
        }
    }

    void postOrderTraversal(Node* node, vector<Key>& result) const {
        if (!node) return;
        for (auto& child : node->children) {
            postOrderTraversal(child.get(), result);
        }
        result.push_back(node->key);
    }

    void inOrderTraversal(Node* node, vector<Key>& result) const {
        if (!node) return;
        if (node->children.size() > 0) {
            inOrderTraversal(node->children[0].get(), result);
        }
        result.push_back(node->key);
        for (size_t i = 1; i < node->children.size(); ++i) {
            inOrderTraversal(node->children[i].get(), result);
        }
    }

public:
    Tree(size_t k = 2) : maxChildren(k) {}

    void add_root(const Key& k) {
        root = make_unique<Node>(k, maxChildren);
    }

    void add_sub_node(const Key& parentKey, const Key& childKey) {
        if (!root) throw runtime_error("Tree is empty");

        queue<Node*> nodes;
        nodes.push(root.get());

        while (!nodes.empty()) {
            Node* node = nodes.front();
            nodes.pop();

            if (node->key == parentKey) {
                for (auto& child : node->children) {
                    if (!child) {
                        child = make_unique<Node>(childKey, maxChildren);
                        return;
                    }
                }
                throw runtime_error("No empty child slot available");
            }

            for (auto& child : node->children) {
                nodes.push(child.get());
            }
        }

        throw runtime_error("Parent node not found");
    }

    // Iterator classes
    class PreOrderIterator {
    private:
        stack<Node*> nodes;

    public:
        PreOrderIterator(Node* root) {
            if (root) nodes.push(root);
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }

        PreOrderIterator& operator++() {
            if (nodes.empty()) return *this;

            Node* current = nodes.top();
            nodes.pop();

            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                if (*it) nodes.push(it->get());
            }

            return *this;
        }

        const Key& operator*() const {
            return nodes.top()->key;
        }
    };

    class PostOrderIterator {
    private:
        stack<pair<Node*, bool>> nodes;

    public:
        PostOrderIterator(Node* root) {
            if (root) nodes.push({root, false});
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }

        PostOrderIterator& operator++() {
            while (!nodes.empty()) {
                auto [current, visited] = nodes.top();
                nodes.pop();

                if (!visited) {
                    nodes.push({current, true});

                    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                        if (*it) nodes.push({it->get(), false});
                    }
                } else {
                    return *this;
                }
            }

            return *this;
        }

        const Key& operator*() const {
            return nodes.top().first->key;
        }
    };

    class InOrderIterator {
    private:
        stack<pair<Node*, size_t>> nodes;

    public:
        InOrderIterator(Node* root) {
            if (root) nodes.push({root, 0});
        }

        bool operator!=(const InOrderIterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }

        InOrderIterator& operator++() {
            while (!nodes.empty()) {
                auto [current, index] = nodes.top();
                nodes.pop();

                if (index < current->children.size()) {
                    nodes.push({current, index + 1});
                    if (current->children[index]) nodes.push({current->children[index].get(), 0});
                    return *this;
                }
            }

            return *this;
        }

        const Key& operator*() const {
            return nodes.top().first->key;
        }
    };

    class BFSIterator {
    private:
        queue<Node*> nodes;

    public:
        BFSIterator(Node* root) {
            if (root) nodes.push(root);
        }

        bool operator!=(const BFSIterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }

        BFSIterator& operator++() {
            if (nodes.empty()) return *this;

            Node* current = nodes.front();
            nodes.pop();

            for (auto& child : current->children) {
                if (child) nodes.push(child.get());
            }

            return *this;
        }

        const Key& operator*() const {
            return nodes.front()->key;
        }
    };

    class DFSIterator {
    private:
        stack<Node*> nodes;

    public:
        DFSIterator(Node* root) {
            if (root) nodes.push(root);
        }

        bool operator!=(const DFSIterator& other) const {
            return !nodes.empty() || !other.nodes.empty();
        }

        DFSIterator& operator++() {
            if (nodes.empty()) return *this;

            Node* current = nodes.top();
            nodes.pop();

            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                if (*it) nodes.push(it->get());
            }

            return *this;
        }

        const Key& operator*() const {
            return nodes.top()->key;
        }
    };

    PreOrderIterator begin_pre_order() const {
        return PreOrderIterator(root.get());
    }

    PreOrderIterator end_pre_order() const {
        return PreOrderIterator(nullptr);
    }

    PostOrderIterator begin_post_order() const {
        return PostOrderIterator(root.get());
    }

    PostOrderIterator end_post_order() const {
        return PostOrderIterator(nullptr);
    }

    InOrderIterator begin_in_order() const {
        return InOrderIterator(root.get());
    }

    InOrderIterator end_in_order() const {
        return InOrderIterator(nullptr);
    }

    BFSIterator begin_bfs_scan() const {
        return BFSIterator(root.get());
    }

    BFSIterator end_bfs_scan() const {
        return BFSIterator(nullptr);
    }

    DFSIterator begin_dfs_scan() const {
        return DFSIterator(root.get());
    }

    DFSIterator end_dfs_scan() const {
        return DFSIterator(nullptr);
    }

    vector<Key> myHeap() {
        vector<Key> result;
        PreOrderIterator it = begin_pre_order();
        while (it != end_pre_order()) {
            result.push_back(*it);
            ++it;
        }
        make_heap(result.begin(), result.end(), greater<Key>());
        return result;
    }

    ~Tree() {
        if (root) {
            queue<Node*> nodes;
            nodes.push(root.get());

            while (!nodes.empty()) {
                Node* current = nodes.front();
                nodes.pop();

                for (auto& child : current->children) {
                    if (child) nodes.push(child.get());
                }

                delete current;
            }
        }
    }
};

int main() {
    Tree<int> tree;
    tree.add_root(1);
    tree.add_sub_node(1, 2);
    tree.add_sub_node(1, 3);
    tree.add_sub_node(2, 4);
    tree.add_sub_node(2, 5);
    tree.add_sub_node(3, 6);

    cout << "Pre-order traversal:" << endl;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "In-order traversal:" << endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "BFS traversal:" << endl;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
