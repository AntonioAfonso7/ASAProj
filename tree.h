#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>
#include <iostream>
#include "treeNode.h"

treeNode getTree(std::vector<int> &v);
void filterMax(std::vector<std::vector<int> > &table);
void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr);

#endif