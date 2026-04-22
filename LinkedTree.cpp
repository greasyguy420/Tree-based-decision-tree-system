#include "LinkedTree.h"

/*
 * implementation of linkedtree methods for managing the decision tree
 * handles node storage lookup and root management
 */

// set the root node of the tree
void LinkedTree::setRoot(Node* node) {
    root = node;
}

// return the root node of the tree
Node* LinkedTree::getRoot() {
    return root;
}

// add a node to the tree by storing it in the position map
void LinkedTree::addNode(Node* node) {
    nodes[node->getPosition()] = node;
}

// retrieve a node from the tree using its position number for instant O(1) lookup
Node* LinkedTree::getNode(int position) {
    if (nodes.find(position) != nodes.end()) {
        return nodes[position];
    }
    return nullptr;
}

// check if a node with given position exists in the tree
bool LinkedTree::nodeExists(int position) {
    return nodes.find(position) != nodes.end();
} 


