//KaryTree.tpp file
#include "KaryTree.hpp"
//members of karyTree: root(ptr node) and size_t maxChildren
template <typename T, size_t K>
KaryTree<T, K>::KaryTree() : root(nullptr), maxChildren(K) {
    // Default constructor for KaryTree with maximum children 2.
}

template <typename T, size_t K>
KaryTree<T, K>::KaryTree(size_t k) : root(nullptr), maxChildren(k) {
    // Constructor for KaryTree with specified maximum children k.
}

template <typename T, size_t K>
KaryTree<T, K>::~KaryTree() {
    // Destructor to free memory allocated for the tree.
    if (root) deleteNode(root);
}

template <typename T, size_t K>
void KaryTree<T, K>::deleteNode(Node* node) {
    // Recursive function to delete nodes and their children.
    for (Node* child : node->children) {
        deleteNode(child);
    }
    delete node;
}

template <typename T, size_t K>
void KaryTree<T, K>::setRoot(const T& key) {
    // Sets the root of the tree to a new node with the given key.
    if (root) deleteNode(root);
    root = new Node(key);
}

template <typename T, size_t K>
bool KaryTree<T, K>::addChild(const T& parentKey, const T& childKey) {
    // Adds a child node with childKey to the node  parentKey, if possible.
    Node* parentNode = findNode(root, parentKey);
    //parent node not null & children size< max k.
    if (parentNode && parentNode->children.size() < maxChildren) {
        parentNode->children.push_back(new Node(childKey));
        return true;
    }
    else if(parentNode->children.size() >= maxChildren){
        cout << "Trying to add more then " << maxChildren << " impossible failed adding child." <<endl;
    }
    return false;
}

template <typename T, size_t K>
typename KaryTree<T, K>::Node* KaryTree<T, K>::findNode(Node* node, const T& key) {
    // Finds and returns a node with the given key in the tree.
    if (!node) return nullptr;
    if (node->key == key) return node;
    for (Node* child : node->children) {
        Node* result = findNode(child, key);
        if (result) return result;
    }
    return nullptr;
}

template <typename T, size_t K>
KaryTree<T, K>::Iterator::Iterator(Node* root) {
    // Constructor for the iterator, starts at the root of the tree.
    if (root) nodesStack.push(root);
    current = nullptr;
    advance();
}

template <typename T, size_t K>
void KaryTree<T, K>::Iterator::advance() {
    // Advances the iterator to the next node using depth-first search(DFS).
    if (nodesStack.empty()) {
        current = nullptr;
        return;
    }

    // Get the top node from the nodes stack.
    current = nodesStack.top();
    // Remove the top node from the stack.
    nodesStack.pop(); 
    // Iterate through the children of the current node in reverse order.
    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
        nodesStack.push(*it);
    }
}


//example:
/**KaryTree<int, 2>::Iterator it = tree.begin();
int key = *it; // מעבר אל ערך המפתח של הקודקוד הנוכחי באיטרטור */ 
template <typename T, size_t K>
T& KaryTree<T, K>::Iterator::operator*() {
    // Dereferences the iterator to get the current node's key.
    return current->key;
}

template <typename T, size_t K>
typename KaryTree<T, K>::Iterator& KaryTree<T, K>::Iterator::operator++() {
    // Prefix increment operator for the iterator.
    advance();
    return *this;
}

template <typename T, size_t K>
bool KaryTree<T, K>::Iterator::operator!=(const Iterator& other) const {
    // Inequality comparison operator for iterators.
    return current != other.current;
}

template <typename T, size_t K>
typename KaryTree<T, K>::Iterator KaryTree<T, K>::begin() {
    // Returns an iterator pointing to the beginning of the tree.
    //return object Iterator of the beginning of the tree(root)
    return Iterator(root);
}

template <typename T, size_t K>
typename KaryTree<T, K>::Iterator KaryTree<T, K>::end() {
    // Returns an iterator pointing to the end of the tree.
    return Iterator(nullptr);
}
