#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>

class treeNode;
void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr);
void filterMax(std::vector<std::vector<int> > &table);
treeNode getTree(std::vector<int> &v);

#endif