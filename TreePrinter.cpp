#include "TreePrinter.h"
#include <sstream>

/*
 * tree printer implementation formats tree structure with proper indentation and writes analysis results to file
 */

void TreePrinter::collectPrintLines(Node* node, int level, std::vector<std::string>& lines) {
    // base case: no node to process
    if (!node) return;

    // build indentation based on level using -- (2 dashes) per level
    std::string indent = "";
    for (int i = 0; i < level; i++) {
        indent += "--";
    }

    // format edge label with brackets only for non-root nodes
    std::string edgeLabel = node->getEdgeLabel();
    std::string edgePart = "";
    if (level > 0 && !edgeLabel.empty()) {
        edgePart = "[" + edgeLabel + "] ";
    }

    // create output line with indent edge label and content
    std::string line = indent + edgePart + node->getContent();
    lines.push_back(line);

    // recursively process all children with increased level
    std::vector<Node*> children = node->getChildren();
    for (Node* child : children) {
        collectPrintLines(child, level + 1, lines);
    }
}

std::string TreePrinter::printTree(Node* root) {
    // collect all lines in visual order
    std::vector<std::string> lines;
    collectPrintLines(root, 0, lines);

    // join all lines with newlines
    std::stringstream ss;
    for (size_t i = 0; i < lines.size(); i++) {
        ss << lines[i];
        if (i < lines.size() - 1) {
            ss << "\n";
        }
    }

    return ss.str();
}

void TreePrinter::writeToFile(LinkedTree& tree, TreeAnalyzer& analyzer, const std::string& filename) {
    // open file for writing
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    // get root node
    Node* root = tree.getRoot();
    if (!root) {
        file.close();
        return;
    }

    // section 1: tree visualization
    file << printTree(root) << "\n\n";

    // separator line
    file << "--------------------\n";
    file << "Tree Properties\n";
    file << "--------------------\n\n";

    // root node information
    file << "Root: " << root->getContent() << "\n";

    // calculate and write counts
    int internalCount = analyzer.countInternal(root);
    int externalCount = analyzer.countExternal(root);
    int height = analyzer.getHeight(root);

    file << "Number of internal nodes: " << internalCount << "\n";
    file << "Number of external nodes: " << externalCount << "\n";
    file << "Tree Height: " << height << "\n\n";

    // internal nodes list
    std::vector<Node*> internalNodes;
    analyzer.preorderInternal(root, internalNodes);
    file << "Internal Nodes:\n";
    for (Node* node : internalNodes) {
        file << node->getContent() << "\n";
    }

    // external nodes list
    std::vector<Node*> externalNodes;
    analyzer.preorderExternal(root, externalNodes);
    file << "\nExternal Nodes:\n";
    for (Node* node : externalNodes) {
        file << node->getContent() << "\n";
    }

    // separator line for binary tree section
    file << "\n--------------------\n";
    file << "Binary Tree Properties\n";
    file << "--------------------\n\n";

    // check if binary tree
    bool isBinary = analyzer.isBinary(root);
    file << "Binary Tree: " << (isBinary ? "Yes" : "No") << "\n";

    // if binary tree check and print additional properties
    if (isBinary) {
        bool isProper = analyzer.isProper(root);
        bool isPerfect = analyzer.isPerfect(root);
        bool isBalanced = analyzer.isBalanced(root);

        file << "Proper Tree: " << (isProper ? "Yes" : "No") << "\n";
        file << "Perfect Tree: " << (isPerfect ? "Yes" : "No") << "\n";
        file << "Balanced Tree: " << (isBalanced ? "Yes" : "No") << "\n";
    }

    // close file
    file.close();
}
