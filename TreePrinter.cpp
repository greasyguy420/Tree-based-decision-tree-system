#include "TreePrinter.h"
#include <sstream>

/*
 * tree printer implementation formats tree structure with proper indentation and writes analysis results to file
 */

void TreePrinter::collectPrintLines(Node* node, int level, std::vector<std::string>& lines) {
    // base case: no node to process
    if (!node) return;

    // build indentation based on level using -- per level
    std::string indent = "";
    for (int i = 0; i < level; i++) {
        indent += "--";
    }

    // format edge label with brackets if not root node
    std::string edgeLabel = node->getEdgeLabel();
    std::string edgePart = "";
    if (!edgeLabel.empty()) {
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

    // section 1: tree visualization header
    file << "Tree Visualization\n\n";
    file << printTree(root) << "\n\n";

    // section 2: tree properties header
    file << "Tree Properties\n";

    // calculate and write counts
    int internalCount = analyzer.countInternal(root);
    int externalCount = analyzer.countExternal(root);
    int height = analyzer.getHeight(root);

    file << "Internal Nodes: " << internalCount << "\n";
    file << "External Nodes (Leaves): " << externalCount << "\n";
    file << "Height: " << height << "\n\n";

    // section 3: binary tree analysis header
    file << "Binary Tree Analysis\n";

    // check and write tree type properties
    bool isBinary = analyzer.isBinary(root);
    bool isProper = analyzer.isProper(root);
    bool isPerfect = analyzer.isPerfect(root);
    bool isBalanced = analyzer.isBalanced(root);

    file << "Is Binary: " << (isBinary ? "Yes" : "No") << "\n";
    file << "Is Proper: " << (isProper ? "Yes" : "No") << "\n";
    file << "Is Perfect: " << (isPerfect ? "Yes" : "No") << "\n";
    file << "Is Balanced: " << (isBalanced ? "Yes" : "No") << "\n";

    // close file
    file.close();
}
