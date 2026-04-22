#include "Explorer.h"
#include <iostream>
#include <algorithm>

/*
 * explorer implementation provides interactive tree navigation with relationship queries
 */

std::vector<Node*> Explorer::getAncestors(Node* node) {
    // collect ancestor chain from node up to root
    std::vector<Node*> ancestors;
    Node* current = node;
    while (current) {
        ancestors.push_back(current);
        current = current->getParent();
    }
    // reverse to have root first
    std::reverse(ancestors.begin(), ancestors.end());
    return ancestors;
}

void Explorer::getDescendants(Node* node, std::vector<Node*>& result) {
    // add current node to result
    result.push_back(node);

    // recursively add all children and their descendants
    std::vector<Node*> children = node->getChildren();
    for (Node* child : children) {
        getDescendants(child, result);
    }
}

std::vector<Node*> Explorer::getSiblings(Node* node) {
    // get all siblings at same level as this node
    std::vector<Node*> siblings;
    Node* parent = node->getParent();

    // if no parent then no siblings
    if (!parent) return siblings;

    // get all children of parent except this node
    std::vector<Node*> parentChildren = parent->getChildren();
    for (Node* child : parentChildren) {
        if (child != node) {
            siblings.push_back(child);
        }
    }

    return siblings;
}

void Explorer::displayNode(int position, Node* node) {
    // print node position and content header
    std::cout << "\nNode Position " << position << "\n";
    std::cout << "Node's content: " << node->getContent() << "\n";

    // get ancestor chain and display immediate parent as ancestor
    std::vector<Node*> ancestors = getAncestors(node);
    if (ancestors.size() > 1) {
        // show parent as the immediate ancestor (second to last in chain since last is the node itself)
        std::cout << "Ancestor: " << ancestors[ancestors.size() - 2]->getContent() << "\n";
    } else {
        std::cout << "Ancestor: (none - this is root)\n";
    }

    // get descendants and display first one
    std::vector<Node*> descendants;
    getDescendants(node, descendants);
    if (descendants.size() > 1) {
        // show first descendant (direct child)
        std::cout << "Descendant: " << descendants[1]->getContent() << "\n";
    } else {
        std::cout << "Descendant: (none - this is a leaf)\n";
    }

    // get siblings and display first one
    std::vector<Node*> siblings = getSiblings(node);
    if (!siblings.empty()) {
        std::cout << "Sibling: " << siblings[0]->getContent() << "\n";
    } else {
        std::cout << "Sibling: (none)\n";
    }
}

void Explorer::startExploration() {
    // interactive console loop for tree exploration
    std::string input;
    bool exploring = true;

    while (exploring) {
        std::cout << "Which node would you like to explore (enter position or \"exit\"): ";
        std::getline(std::cin, input);

        // check for exit command
        if (input == "exit" || input == "quit") {
            exploring = false;
            std::cout << "Goodbye!\n";
            break;
        }

        // parse position as integer
        int position;
        try {
            position = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        // look up node at position
        if (!tree.nodeExists(position)) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        // get and display node information
        Node* node = tree.getNode(position);
        displayNode(position, node);
    }
}
