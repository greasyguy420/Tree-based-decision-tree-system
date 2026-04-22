#ifndef LINKEDTREE_H
#define LINKEDTREE_H

#include "Node.h"
#include <map>
using namespace std;

/*
 * manages the entire decision tree with efficient node lookup
 * maintains root pointer and position map for O(1) access to any node
 */
class LinkedTree {
private:
    Node* root;
    map<int, Node*> nodes;

public:
    // initialize tree with no root and empty node map
    LinkedTree() {
        root = nullptr;
    }

    // set the root node of the tree
    void setRoot(Node* node);

    // return the root node of the tree
    Node* getRoot();

    // add a node to the tree by storing it in the position map
    void addNode(Node* node);

    // retrieve a node from the tree using its position number for instant lookup
    Node* getNode(int position);

    // check if a node with given position exists in the tree
    bool nodeExists(int position);
};

#endif