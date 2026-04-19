#include <vector>
using namespace std;

//Structure of a node in the decision tree
class Node {
public:
    char content[100];
    char edge[10];
    int level;
    int position;
    Node* parent;
    vector<Node*> children;

    Node() {
        parent = nullptr;
    }
};