#include "FileReader.h"
#include <sstream>

/*
 * implementation of file reader for parsing decision tree input files
 * extracts level position edge label and content from each line
 */

// read file and parse each line into level position edge label and content
vector<ParsedLine> FileReader::readFile(string filename) {
    vector<ParsedLine> lines;
    ifstream file(filename);
    
    // check if file opened successfully and handle error
    if (!file.is_open()) {
        return lines;
    }
    
    string line;
    // read each line from file and parse into structured format
    while (getline(file, line)) {
        // skip empty lines or lines with no content
        if (line.empty()) {
            continue;
        }
        
        ParsedLine parsed;
        stringstream ss(line);
        int level, position;
        
        // extract level and position first
        if (!(ss >> level >> position)) {
            continue;
        }
        
        parsed.level = level;
        parsed.position = position;
        
        // for root nodes level 0 no edge label all remaining text is content
        if (level == 0) {
            parsed.edgeLabel = "";
            string remaining;
            getline(ss, remaining);
            if (!remaining.empty() && remaining[0] == ' ') {
                remaining = remaining.substr(1);
            }
            parsed.content = remaining;
        } else {
            // for non-root nodes extract edge label then remaining is content
            if (!(ss >> parsed.edgeLabel)) {
                continue;
            }
            string remaining;
            getline(ss, remaining);
            if (!remaining.empty() && remaining[0] == ' ') {
                remaining = remaining.substr(1);
            }
            parsed.content = remaining;
        }
        
        lines.push_back(parsed);
    }
    
    file.close();
    return lines;
}
