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
    Node(string content);

    void setParent(Node* node);
    void addChild(Node* node);
    void setEdgeLabel(string edge);
    void setPosition(int pos);
    void setLevel(int lvl);

    string getContent();
    Node* getParent();
    vector<Node*> getChildren();
    string getEdgeLabel();
    int getPosition();
    int getLevel();
};

#endif