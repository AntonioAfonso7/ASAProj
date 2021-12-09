#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "treeNode.h"

treeNode getTree(std::vector<int> &v);
void filterMax(std::vector<std::vector<int> > &table);
void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr);
void getLongestVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr);
void printTree(treeNode t);

#endif