# Tree-based-decision-tree-system

This project implements a general linked decision tree system for Data Structures Project 3.

The program:

- reads tree data from input files
- builds a linked tree dynamically
- analyzes tree properties
- writes analysis results to about_tree.txt
- supports interactive node exploration from the console

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

## Main Features

1. Tree Construction

- no hardcoded tree logic
- works for valid input files following the required format
- parent-child links are built dynamically

2. Output File Generation

- creates about_tree.txt
- includes tree visualization with 2-dash indentation per level
- includes edge labels in bracket format like [Yes] and [No]
- includes root, internal and external counts, height, and preorder lists
- includes binary tree analysis

3. Interactive Exploration

- prompt: Which node would you like to explore (enter position or "exit"):
- for valid position: shows node content, one ancestor, one descendant, and one sibling
- invalid input: Invalid input. Please try again.
- exit input: Goodbye!

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

## about_tree.txt Contents

The generated file includes these sections:

- Tree Visualization
- Tree Properties
  - Root
  - Number of internal nodes
  - Number of external nodes
  - Tree Height
  - Internal Nodes (preorder)
  - External Nodes (preorder)
- Binary Tree Properties
  - Binary Tree: Yes/No
  - If binary is Yes: Proper Tree, Perfect Tree, Balanced Tree

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
