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
    std::cout << "\n===== Node Position " << position << " =====\n";
    std::cout << "Content: " << node->getContent() << "\n";

    // get and display ancestors chain from root to node
    std::vector<Node*> ancestors = getAncestors(node);
    std::cout << "\nAncestors (path from root):\n";
    for (size_t i = 0; i < ancestors.size(); i++) {
        std::cout << "  ";
        for (size_t j = 0; j < i; j++) {
            std::cout << "  ";
        }
        std::cout << "-> " << ancestors[i]->getContent() << "\n";
    }

    // get and display all descendants
    std::vector<Node*> descendants;
    getDescendants(node, descendants);
    std::cout << "\nDescendants (" << (descendants.size() - 1) << " total):\n";
    for (size_t i = 1; i < descendants.size(); i++) {
        std::cout << "  - " << descendants[i]->getContent();
        if (!descendants[i]->getEdgeLabel().empty()) {
            std::cout << " [" << descendants[i]->getEdgeLabel() << "]";
        }
        std::cout << "\n";
    }

    // get and display siblings
    std::vector<Node*> siblings = getSiblings(node);
    std::cout << "\nSiblings (" << siblings.size() << " total):\n";
    if (siblings.empty()) {
        std::cout << "  (no siblings)\n";
    } else {
        for (Node* sibling : siblings) {
            std::cout << "  - " << sibling->getContent() << "\n";
        }
    }
}

void Explorer::startExploration() {
    // interactive console loop for tree exploration
    std::string input;
    bool exploring = true;

    std::cout << "\n===== Tree Explorer =====\n";
    std::cout << "Enter node position to explore or type exit to quit\n";

    while (exploring) {
        std::cout << "\nEnter position (or exit): ";
        std::getline(std::cin, input);

        // check for exit command
        if (input == "exit" || input == "quit") {
            exploring = false;
            std::cout << "Exiting explorer.\n";
            break;
        }

        // parse position as integer
        int position;
        try {
            position = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid position number.\n";
            continue;
        }

        // look up node at position
        if (!tree.nodeExists(position)) {
            std::cout << "No node found at position " << position << "\n";
            continue;
        }

        // get and display node information
        Node* node = tree.getNode(position);
        displayNode(position, node);
    }
}
