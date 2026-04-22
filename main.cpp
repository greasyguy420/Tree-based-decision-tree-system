#include "FileReader.h"
#include "TreeBuilder.h"
#include "TreeAnalyzer.h"
#include "TreePrinter.h"
#include "Explorer.h"
#include <iostream>

/*
 * main orchestrates complete decision tree system workflow
 * reads file, builds tree, analyzes properties, prints output, launches interactive explorer
 */

int main(int argc, char* argv[]) {
    // validate command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::string filename = argv[1];

    // phase 1: read and parse input file
    std::cout << "Reading file: " << filename << "\n";
    FileReader reader;
    std::vector<ParsedLine> lines;
    try {
        lines = reader.readFile(filename);
    } catch (const std::exception& e) {
        std::cerr << "Error reading file: " << e.what() << "\n";
        return 1;
    }

    if (lines.empty()) {
        std::cerr << "File is empty or could not be parsed\n";
        return 1;
    }

    std::cout << "Successfully parsed " << lines.size() << " lines\n";

    // phase 2: build tree from parsed lines
    std::cout << "Building tree...\n";
    LinkedTree tree;
    TreeBuilder builder;
    try {
        builder.buildTree(lines, tree);
    } catch (const std::exception& e) {
        std::cerr << "Error building tree: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Tree built successfully\n";

    // phase 3: analyze tree properties
    std::cout << "Analyzing tree...\n";
    TreeAnalyzer analyzer;

    std::cout << "Tree analysis complete\n";

    // phase 4: print tree and write output file
    std::cout << "Generating output...\n";
    TreePrinter printer;
    try {
        printer.writeToFile(tree, analyzer, "about_tree.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error writing output file: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Output written to about_tree.txt\n\n";

    // phase 5: start interactive explorer
    Explorer explorer(tree);
    explorer.startExploration();

    return 0;
}
