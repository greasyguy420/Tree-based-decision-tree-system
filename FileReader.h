#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
 * represents a single line of parsed data from the input file
 * stores level position edge label and node content for tree construction
 */
struct ParsedLine {
    int level;
    int position;
    string edgeLabel;
    string content;
};

/*
 * reads tree data from input files and parses them into structured line objects
 * handles file parsing and returns vector of parsed lines for tree building
 */
class FileReader {
public:
    // read file and parse each line into level position edge label and content
    vector<ParsedLine> readFile(string filename);
};

#endif