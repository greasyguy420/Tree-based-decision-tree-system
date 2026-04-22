#include "Node.h"

/*
 * implementation of the node class constructor and all getter setter methods
 * handles initialization and data access for decision tree nodes
 */

// initialize node with content and set all other values to defaults
Node::Node(string content) {
    this->content = content;
    parent = nullptr;
    edgeLabel = "";
    position = 0;
    level = 0;
}

// assign a parent node to this node
void Node::setParent(Node* node) {
    parent = node;
}

// add a child node to this node's children list
void Node::addChild(Node* node) {
    children.push_back(node);
}

// set the edge label that identifies the relationship to parent
void Node::setEdgeLabel(string edge) {
    edgeLabel = edge;
}

// set the position identifier for this node from the input file
void Node::setPosition(int pos) {
    position = pos;
}

// set the depth level of this node in the tree
void Node::setLevel(int lvl) {
    level = lvl;
}

// return the content string of this node
string Node::getContent() {
    return content;
}

// return pointer to the parent node or null if root
Node* Node::getParent() {
    return parent;
}

// return the list of all child nodes
vector<Node*> Node::getChildren() {
    return children;
}

// return the edge label connecting to parent
string Node::getEdgeLabel() {
    return edgeLabel;
}

// return the position number of this node
int Node::getPosition() {
    return position;
}

// return the level depth of this node
int Node::getLevel() {
    return level;
}
