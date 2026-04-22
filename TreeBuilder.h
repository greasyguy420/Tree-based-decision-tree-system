#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include "LinkedTree.h"
#include "FileReader.h"
#include <vector>
#include <map>
using namespace std;

/*
 * constructs the decision tree from parsed input lines
 * links nodes together by level and maintains parent child relationships
 */
class TreeBuilder {
public:
    // build tree structure from parsed lines and add all nodes to linkedtree
    void buildTree(vector<ParsedLine> lines, LinkedTree &tree);
};

#endif