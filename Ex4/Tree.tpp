// Mail: kolanielioz@gmail.com 

template <typename T, int K>
Tree<T, K>::Tree() : root(nullptr), max_children(K) {}

// Destructor for tree
template <typename T, int K>
Tree<T, K>::~Tree()
{
    destroy(root);
}

template <typename T, int K>
void Tree<T, K>::destroy(Node<T> *node)
{
    if (node == nullptr)
        return;
    for (auto child : node->children)
    {
        destroy(child);
    }
    delete node;
}

template <typename T, int K>
void Tree<T, K>::add_root(Node<T> &value)
{
    if (root != nullptr)
    {
        delete root;
    }
    root = new Node<T>(value.data);
}

template <typename T, int K>
void Tree<T, K>::add_sub_node(const Node<T> &parent_value, const Node<T> &child_value)
{
    if (root == nullptr)
        return;

    Node<T> *parent_node = find_node(root, parent_value.data);
    if (parent_node == nullptr)
        return;

    if (parent_node->children.size() < static_cast<size_t>(max_children))
    {
        Node<T> *child_node = new Node<T>(child_value.data);
        parent_node->children.push_back(child_node);
    }
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_pre_order() const
{
    std::vector<Node<T> *> result;
    pre_order(root, result);
    return Iterator(result, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_pre_order() const
{
    std::vector<Node<T> *> result;
    pre_order(root, result);
    return Iterator(result, result.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_post_order() const
{
    std::vector<Node<T> *> result;
    post_order(root, result);
    return Iterator(result, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_post_order() const
{
    std::vector<Node<T> *> result;
    post_order(root, result);
    return Iterator(result, result.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_in_order() const
{
    std::vector<Node<T> *> result;
    in_order(root, result);
    return Iterator(result, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_in_order() const
{
    std::vector<Node<T> *> result;
    in_order(root, result);
    return Iterator(result, result.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_dfs_scan() const
{
    std::vector<Node<T> *> result;
    DFS_scan(root, result);
    return Iterator(result, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_dfs_scan() const
{
    std::vector<Node<T> *> result;
    DFS_scan(root, result);
    return Iterator(result, result.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_bfs_scan() const
{
    std::vector<Node<T> *> result;
    bfs_scan(root, result);
    return Iterator(result, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_bfs_scan() const
{
    std::vector<Node<T> *> result;
    bfs_scan(root, result);
    return Iterator(result, result.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin_heap_order() const
{
    std::vector<Node<T> *> heap_nodes;
    myHeap(root, heap_nodes);
    return Iterator(heap_nodes, 0);
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end_heap_order() const
{
    std::vector<Node<T> *> heap_nodes;
    myHeap(root, heap_nodes);
    return Iterator(heap_nodes, heap_nodes.size());
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::begin() const
{
    return begin_bfs_scan();
}

template <typename T, int K>
typename Tree<T, K>::Iterator Tree<T, K>::end() const
{
    return end_bfs_scan();
}

template <typename T, int K>
Node<T> *Tree<T, K>::find_node(Node<T> *node, const T &value) const
{ // Ensure this matches the declaration
    if (node == nullptr)
        return nullptr;
    if (node->data == value)
        return node;
    for (auto child : node->children)
    {
        Node<T> *found_node = find_node(child, value);
        if (found_node != nullptr)
            return found_node;
    }
    return nullptr;
}

template <typename T, int K>
void Tree<T, K>::pre_order(Node<T> *node, std::vector<Node<T> *> &result) const
{
    if (node == nullptr)
        return;
    result.push_back(node);
    for (auto child : node->children)
    {
        pre_order(child, result);
    }
}

/**
 * Perform post-order traversal on a tree rooted at `node`.
 * This function collects nodes in the traversal sequence into the `result` vector.
 * @note Post-order traversal visits nodes in the following sequence:
 *       - For binary trees (K == 2): Left subtree, Right subtree, Root.
 *       - For K-ary trees (K > 2): Each child subtree, followed by the Root DFS.
 */
template <typename T, int K>
void Tree<T, K>::post_order(Node<T> *node, std::vector<Node<T> *> &result) const
{
    if (node == nullptr)
        return;

    if (K == 2)
    {
        // Binary tree post-order traversal

        // Check if the current node has a left child:
        // If there is a left child, call post_order on it.
        // If there is no left child, pass nullptr to the post_order function.
        // if there is left child in the node has to have at list one child
        post_order(node->children.size() > 0 ? node->children[0] : nullptr, result); // Left
        // Check if the current node has a right child:
        // If there is a right child, call post_order on it.
        // If there is no right child, pass nullptr to the post_order function.
        // if there is left child in the node has to have at list two childs
        post_order(node->children.size() > 1 ? node->children[1] : nullptr, result); // Right
        result.push_back(node);                                                      // Root
    }
    else
    {
        // K-ary tree depth-first search (DFS) traversal
        std::stack<Node<T> *> nodes;
        nodes.push(node);
        while (!nodes.empty())
        {
            Node<T> *current = nodes.top();
            nodes.pop();
            result.push_back(current); // Add node to result vector

            // Push children in reverse order to simulate DFS
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
            {
                nodes.push(*it);
            }
        }
    }
}

/**
 * in order traversal for Binary trees
 * if the tree is not Binary tree do DFS traversal.
 */
template <typename T, int K>
void Tree<T, K>::in_order(Node<T> *node, std::vector<Node<T> *> &result) const
{
    if (node == nullptr)
        return;

    if (K == 2)
    {
        // Binary tree in-order traversal
        if (node->children.size() >= 1)
            in_order(node->children[0], result);

        result.push_back(node);

        if (node->children.size() >= 2)
            in_order(node->children[1], result);
    }
    else
    {
        // K-ary tree DFS traversal
        result.push_back(node); // Push current node

        for (auto child : node->children)
        {
            in_order(child, result); // Recursively traverse children
        }
    }
}

template <typename T, int K>
void Tree<T, K>::bfs_scan(Node<T> *node, std::vector<Node<T> *> &result) const
{
    if (node == nullptr)
        return;
    std::queue<Node<T> *> nodes;
    nodes.push(node);
    while (!nodes.empty())
    {
        Node<T> *current = nodes.front();
        nodes.pop();
        result.push_back(current);
        for (auto child : current->children)
        {
            nodes.push(child);
        }
    }
}

template <typename T, int K>
void Tree<T, K>::DFS_scan(Node<T> *node, std::vector<Node<T> *> &result) const
{
    if (node == nullptr)
        return;
    std::stack<Node<T> *> nodes;
    nodes.push(node);
    while (!nodes.empty())
    {
        Node<T> *current = nodes.top();
        nodes.pop();
        result.push_back(current);
        // Push children in reverse order to achieve DFS
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
        {
            nodes.push(*it);
        }
    }
}

template <typename T, int K>
void Tree<T, K>::myHeap(Node<T> *node, std::vector<Node<T> *> &result) const
{
    // If the node is null, there's nothing to myHeap
    if (node == nullptr)
        return;

    // Create a priority queue to hold the nodes, ordered by HeapComparator
    // This ensures that the smallest element (according to HeapComparator) is at the top
    std::priority_queue<Node<T> *, std::vector<Node<T> *>, HeapComparator<T>> priorityQueue;

    // Start by pushing the root node into the priority queue
    priorityQueue.push(node);

    // Process the nodes in the priority queue until it's empty
    while (!priorityQueue.empty())
    {
        // Get the node with the smallest value with HeapComparator from the queue
        Node<T> *current = priorityQueue.top();
        priorityQueue.pop();

        // Add this node to the result vector
        result.push_back(current);

        // Push all the children of the current node into the priority queue
        for (auto child : current->children)
        {
            priorityQueue.push(child);
        }
    }
}

template <typename T, int K>
Tree<T, K>::Iterator::Iterator(const std::vector<Node<T> *> &nodes, size_t idx) : nodes(nodes), index(idx) {}

template <typename T, int K>
typename Tree<T, K>::Iterator &Tree<T, K>::Iterator::operator++()
{
    ++index;
    return *this;
}

template <typename T, int K>
bool Tree<T, K>::Iterator::operator!=(const Iterator &other) const
{
    return index != other.index;
}

template <typename T, int K>
Node<T> *Tree<T, K>::Iterator::operator*() const
{
    return nodes[index];
}

template <typename T, int K>
Node<T> *Tree<T, K>::Iterator::operator->() const
{
    return nodes[index];
}

//****************************GUI**********************/


template <typename T, int K>
void Tree<T, K>::draw_tree(sf::RenderWindow &window, Node<T> *node, float x, float y, float x_offset, float y_offset) const
{
    if (!node)
        return;

    sf::CircleShape shape(55);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
    //shape.setOrigin(50, 50); // Set origin to center of circle
    window.draw(shape);

    sf::Font font; // Local variable for font

    if (!font.loadFromFile("/home/elioz/System Programming/Ex4/arial.ttf"))
    {
        std::cerr << "Failed to load font 'arial.ttf'" << std::endl;
        // Handle failure appropriately
    }

    // Assuming font is a member variable of Tree class and initialized elsewhere
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(node->data));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 30);//  text position 

    window.draw(text);

    float child_x = x - x_offset * (node->children.size() - 1) / 2;
    for (auto *child : node->children)
    {
        if (child)
        {
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 30, y + 30)), //  line start point
                    sf::Vertex(sf::Vector2f(child_x + 30, y + y_offset + 30)) // line end point
                };
            window.draw(line, 2, sf::Lines);
            draw_tree(window, child, child_x, y + y_offset, x_offset / 2, y_offset + 100); //y_offset for more vertical spacing
            child_x += x_offset + 50; //  x_offset for more horizontal spacing
        }
    }
}

template <typename T, int K>
void Tree<T, K>::print() const
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    if (!window.isOpen()) return; // Check if window opened correctly

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font 'arial.ttf'" << std::endl;
        return;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        draw_tree(window, root, 400, 20, 200, 100); // Adjust these parameters as needed
        window.display();
    }
}



// Explicit template instantiation for commonly used types
template class Tree<int>;
template class Tree<double>;
template class Tree<std::string>;
