#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <vector>
#include <string>
#include <iostream>

class treeNode
{
private:
    int value;
    std::vector<treeNode> sons;

public:
    treeNode(int n);
    void setValue(int n);
    void insert(treeNode &t, int n);
    std::vector<treeNode> getSons();
    int getValue();
    void print();
}; 

#endif