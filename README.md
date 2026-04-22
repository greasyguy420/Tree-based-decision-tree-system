# Tree-based-decision-tree-system

This project builds a general linked decision tree from input files, analyzes tree properties, writes the analysis to about_tree.txt, and provides an interactive explorer.

## Project Structure

- Node.h / Node.cpp
- LinkedTree.h / LinkedTree.cpp
- FileReader.h / FileReader.cpp
- TreeBuilder.h / TreeBuilder.cpp
- TreeAnalyzer.h / TreeAnalyzer.cpp
- TreePrinter.h / TreePrinter.cpp
- Explorer.h / Explorer.cpp
- main.cpp
- tree-car.txt
- tree-investment.txt

## Compile Instructions (Linux cluster)

Use g++ to compile all files into one executable:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Node.cpp LinkedTree.cpp FileReader.cpp TreeBuilder.cpp TreeAnalyzer.cpp TreePrinter.cpp Explorer.cpp main.cpp -o tree_system
```

## Run Instructions

Run with the car decision file:

```bash
./tree_system tree-car.txt
```

Run with the investment decision file:

```bash
./tree_system tree-investment.txt
```

The program generates:

- about_tree.txt

## Input File Format

Each line is space-separated with this structure:

- level
- preorder position
- edge label (non-root lines)
- node content

Root line uses:

- level and position, followed directly by root content

Example:

```text
0 1 Are you nervous?
1 2 Yes Savings account
1 3 No Will you need to access most of the money within the next 5 years?
```
