#include "TreeAnalyzer.h"
#include <algorithm>
#include <functional>

/*
 * implementation of tree analyzer for computing tree properties and traversals
 * provides recursive functions for analysis of tree structure and node relationships
 */

// count nodes with at least one child
int TreeAnalyzer::countInternal(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    
    // check if this node has children making it internal
    int count = 0;
    if (node->getChildren().size() > 0) {
        count = 1;
    }
    
    // recursively count internal nodes in all children
    for (Node* child : node->getChildren()) {
        count += countInternal(child);
    }
    
    return count;
}

// count nodes with no children (leaf nodes)
int TreeAnalyzer::countExternal(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    
    // check if this node is external (no children)
    int count = 0;
    if (node->getChildren().size() == 0) {
        count = 1;
    }
    
    // recursively count external nodes in all children
    for (Node* child : node->getChildren()) {
        count += countExternal(child);
    }
    
    return count;
}

// calculate maximum depth from root to leaf
int TreeAnalyzer::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    
    // if leaf node height is 0
    if (node->getChildren().size() == 0) {
        return 0;
    }
    
    // find maximum height among all children
    int maxChildHeight = -1;
    for (Node* child : node->getChildren()) {
        maxChildHeight = max(maxChildHeight, getHeight(child));
    }
    
    return 1 + maxChildHeight;
}

// collect all internal nodes in preorder traversal
void TreeAnalyzer::preorderInternal(Node* node, vector<Node*> &result) {
    if (node == nullptr) {
        return;
    }
    
    // add node to result if it is internal
    if (node->getChildren().size() > 0) {
        result.push_back(node);
    }
    
    // traverse all children in order
    for (Node* child : node->getChildren()) {
        preorderInternal(child, result);
    }
}

// collect all external nodes in preorder traversal
void TreeAnalyzer::preorderExternal(Node* node, vector<Node*> &result) {
    if (node == nullptr) {
        return;
    }
    
    // add node to result if it is external (leaf)
    if (node->getChildren().size() == 0) {
        result.push_back(node);
    }
    
    // traverse all children in order
    for (Node* child : node->getChildren()) {
        preorderExternal(child, result);
    }
}

// check if all nodes have at most 2 children
bool TreeAnalyzer::isBinary(Node* node) {
    if (node == nullptr) {
        return true;
    }
    
    // if node has more than 2 children it is not binary
    if (node->getChildren().size() > 2) {
        return false;
    }
    
    // check all children recursively
    for (Node* child : node->getChildren()) {
        if (!isBinary(child)) {
            return false;
        }
    }
    
    return true;
}

// check if all nodes have either 0 or 2 children
bool TreeAnalyzer::isProper(Node* node) {
    if (node == nullptr) {
        return true;
    }
    
    int childCount = node->getChildren().size();
    
    // proper tree requires 0 or 2 children not 1
    if (childCount == 1) {
        return false;
    }
    
    // check all children recursively
    for (Node* child : node->getChildren()) {
        if (!isProper(child)) {
            return false;
        }
    }
    
    return true;
}

// check if height difference between left and right subtrees is at most 1
bool TreeAnalyzer::isBalanced(Node* node) {
    if (node == nullptr) {
        return true;
    }
    
    vector<Node*> children = node->getChildren();
    
    // for nodes with 0 or 1 child always balanced
    if (children.size() <= 1) {
        for (Node* child : children) {
            if (!isBalanced(child)) {
                return false;
            }
        }
        return true;
    }
    
    // for binary nodes check height difference
    int height1 = getHeight(children[0]);
    int height2 = getHeight(children[1]);
    
    if (abs(height1 - height2) > 1) {
        return false;
    }
    
    // check if both subtrees are balanced
    for (Node* child : children) {
        if (!isBalanced(child)) {
            return false;
        }
    }
    
    return true;
}

// check if all nodes have same height and all levels full
bool TreeAnalyzer::isPerfect(Node* node) {
    if (node == nullptr) {
        return true;
    }
    
    // perfect tree requires all nodes to have either 0 or same number of children
    int height = getHeight(node);
    
    // check recursively if tree is perfect by verifying all leaves at same level
    function<int(Node*)> checkPerfectHeight = [&](Node* n) -> int {
        if (n == nullptr) {
            return -1;
        }
        
        vector<Node*> children = n->getChildren();
        
        // leaf node is perfect with height 0
        if (children.size() == 0) {
            return 0;
        }
        
        // get height of first child
        int firstChildHeight = checkPerfectHeight(children[0]);
        if (firstChildHeight == -1) {
            return -1;
        }
        
        // all children must have same height for perfect tree
        for (int i = 1; i < children.size(); i++) {
            if (checkPerfectHeight(children[i]) != firstChildHeight) {
                return -1;
            }
        }
        
        return 1 + firstChildHeight;
    };
    
    return checkPerfectHeight(node) == height;
}