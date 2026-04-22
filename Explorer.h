#ifndef EXPLORER_H
#define EXPLORER_H

#include "LinkedTree.h"
#include <string>
#include <vector>

/*
 * explorer provides interactive console interface for navigating and querying the decision tree
 * allows users to look up nodes by position and explore relationships
 */

class Explorer {
private:
    LinkedTree& tree;

    // display a single node with its position and relationships
    void displayNode(int position, Node* node);

    // get ancestors of node as ordered chain from root to node
    std::vector<Node*> getAncestors(Node* node);

    // get all descendants of node in preorder traversal
    void getDescendants(Node* node, std::vector<Node*>& result);

    // get all sibling nodes at same level
    std::vector<Node*> getSiblings(Node* node);

public:
    // initialize explorer with tree reference
    Explorer(LinkedTree& t) : tree(t) {}

    // start interactive console loop for tree exploration
    void startExploration();
};

#endif
