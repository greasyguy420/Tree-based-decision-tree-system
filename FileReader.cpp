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
        
        // extract the four components separated by spaces from each line
        if (ss >> parsed.level >> parsed.position >> parsed.edgeLabel) {
            // get remaining content after label
            getline(ss, parsed.content);
            
            // trim leading space from content
            if (!parsed.content.empty() && parsed.content[0] == ' ') {
                parsed.content = parsed.content.substr(1);
            }
            
            lines.push_back(parsed);
        }
    }
    
    file.close();
    return lines;
}
