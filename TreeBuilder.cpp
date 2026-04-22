#include "TreeBuilder.h"
#include <algorithm>

/*
 * implementation of treebuilder for constructing linked tree from parsed lines
 * handles node creation linking and tree population
 */

// build tree structure from parsed lines and add all nodes to linkedtree
void TreeBuilder::buildTree(vector<ParsedLine> lines, LinkedTree &tree) {
    if (lines.empty()) {
        return;
    }

    // sort by preorder position so parent child relationships are built correctly
    sort(lines.begin(), lines.end(), [](const ParsedLine& a, const ParsedLine& b) {
        return a.position < b.position;
    });
    
    map<int, Node*> lastNodeAtLevel;
    
    // create root node from first parsed line
    Node* root = new Node(lines[0].content);
    root->setPosition(lines[0].position);
    root->setLevel(lines[0].level);
    root->setEdgeLabel(lines[0].edgeLabel);
    tree.setRoot(root);
    tree.addNode(root);
    lastNodeAtLevel[0] = root;
    
    // process each remaining line and build tree structure
    for (size_t i = 1; i < lines.size(); i++) {
        ParsedLine &parsed = lines[i];
        
        // create new node with parsed data
        Node* newNode = new Node(parsed.content);
        newNode->setPosition(parsed.position);
        newNode->setLevel(parsed.level);
        newNode->setEdgeLabel(parsed.edgeLabel);
        
        // find parent node from previous level
        int parentLevel = parsed.level - 1;
        if (lastNodeAtLevel.find(parentLevel) != lastNodeAtLevel.end()) {
            Node* parent = lastNodeAtLevel[parentLevel];
            
            // link parent to child and child to parent both ways
            newNode->setParent(parent);
            parent->addChild(newNode);
        }
        
        // update the last node at this level
        lastNodeAtLevel[parsed.level] = newNode;
        
        // add node to tree map for quick lookup
        tree.addNode(newNode);
    }
}
