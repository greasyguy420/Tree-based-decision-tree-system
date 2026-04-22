#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
using namespace std;

/*
 * represents a single node in the decision tree with parent child relationships
 * stores content edge label position and level for tree traversal and analysis
 */
class Node {
private:    
    string content;
    Node* parent;
    vector<Node*> children;
    string edgeLabel;
    int position;
    int level;

public:
    // initialize node with content and set all other values to defaults
    Node(string content) {
        this->content = content;
        parent = nullptr;
        edgeLabel = "";
        position = 0;
        level = 0;
    }

    // assign a parent node to this node
    void setParent(Node* node) {
        parent = node;
    }

    // add a child node to this node's children list
    void addChild(Node* node) {
        children.push_back(node);
    }

    // set the edge label that identifies the relationship to parent
    void setEdgeLabel(string edge) {
        edgeLabel = edge;
    }

    // set the position identifier for this node from the input file
    void setPosition(int pos) {
        position = pos;
    }

    // set the depth level of this node in the tree
    void setLevel(int lvl) {
        level = lvl;
    }

    // return the content string of this node
    string getContent() {
        return content;
    }

    // return pointer to the parent node or null if root
    Node* getParent() {
        return parent;
    }

    // return the list of all child nodes
    vector<Node*> getChildren() {
        return children;
    }

    // return the edge label connecting to parent
    string getEdgeLabel() {
        return edgeLabel;
    }

    // return the position number of this node
    int getPosition() {
        return position;
    }

    // return the level depth of this node
    int getLevel() {
        return level;
    }
};

#endif