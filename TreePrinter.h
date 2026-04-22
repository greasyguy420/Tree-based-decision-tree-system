#ifndef TREEPRINTER_H
#define TREEPRINTER_H

#include "Node.h"
#include "LinkedTree.h"
#include "TreeAnalyzer.h"
#include <string>
#include <vector>
#include <fstream>

/*
 * tree printer formats and outputs tree visualization and analysis results
 * provides methods to print tree structure with indentation and write formatted output to file
 */

class TreePrinter {
private:
    // collect tree nodes in visual order for printing with indentation levels
    void collectPrintLines(Node* node, int level, std::vector<std::string>& lines);

public:
    // print tree starting from root node with recursive indentation
    std::string printTree(Node* root);

    // write complete tree visualization and analysis results to file
    void writeToFile(LinkedTree& tree, TreeAnalyzer& analyzer, const std::string& filename);
};

#endif
