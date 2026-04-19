# Tree-based-decision-tree-system
Reads tree data from files, Constructs the tree dynamically, Analyzes tree properties , and Allows interactive exploration


## Project Structure
- main.cpp  
- Node.h  
- LinkedTree.cpp / LinkedTree.h  
- TreeAnalyzer.cpp / TreeAnalyzer.h  

## File Descriptions

### Node.h
- Defines the structure of a tree node

### LinkedTree.h / LinkedTree.cpp
- Implements the tree logic and operations

### main.cpp
- Controls program flow and user interaction

## Input File Format
Each input file should follow this format:

- First line: Root node content  
- Each subsequent line contains:
  - Level  
  - Preorder Position  
  - Edge Label  
  - Node Content

### Example:
```
0 1 Are you nervous?
1 2 Yes Savings account
1 3 No Will you need to access most of the money within the next 5 years?```
