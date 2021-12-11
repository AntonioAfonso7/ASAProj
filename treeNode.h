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
    bool root;

public:
    treeNode(int n);
    treeNode(int n, bool b);
    void setValue(int n);
    bool isRoot();
    void insert(treeNode &t, int n);
    std::vector<treeNode> getSons();
    void printTree(treeNode t);
    int getValue();
    void print();
}; 

#endif