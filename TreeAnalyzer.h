#ifndef TREEANALYZER_H
#define TREEANALYZER_H

#include "Node.h"
#include <vector>
using namespace std;

/*
 * analyzes tree properties like height internal external nodes and tree types
 * provides functions for counting nodes traversing and checking binary properties
 */
class TreeAnalyzer {
public:
    // count nodes with at least one child
    int countInternal(Node* node);
    
    // count nodes with no children (leaf nodes)
    int countExternal(Node* node);
    
    // calculate maximum depth from root to leaf
    int getHeight(Node* node);
    
    // collect all internal nodes in preorder traversal
    void preorderInternal(Node* node, vector<Node*> &result);
    
    // collect all external nodes in preorder traversal
    void preorderExternal(Node* node, vector<Node*> &result);
    
    // check if all nodes have at most 2 children
    bool isBinary(Node* node);
    
    // check if all nodes have either 0 or 2 children
    bool isProper(Node* node);
    
    // check if all nodes have same height and all levels full
    bool isPerfect(Node* node);
    
    // check if height difference between left and right subtrees is at most 1
    bool isBalanced(Node* node);
};

#endif