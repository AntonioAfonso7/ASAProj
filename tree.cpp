#include "tree.h"

void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr)
{
    if (t.treeNode::getSons().size() == 0)
    {
        curArr.push_back(t.treeNode::getValue());
        dest.push_back(curArr);
    }
    else
    {
        std::vector<int> tmp(curArr);
        tmp.push_back(t.treeNode::getValue());
        dest.push_back(tmp);
        for (int i = 0; i < t.treeNode::getSons().size(); i++)
        {
            getAllVectors(t.treeNode::getSons()[i], dest, tmp);
        }
    }
}

void filterMax(std::vector<std::vector<int> > &table)
{
    std::vector<std::vector<int> > tmp;

    int max_size = 0;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].size() > max_size)
        {
            max_size = table[i].size();
        }
    }

    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].size() == max_size)
        {
            tmp.push_back(table[i]);
        }
    }

    table = tmp;
}

treeNode getTree(std::vector<int> &v)
{
    treeNode tree(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        tree.treeNode::insert(tree, v[i]);
    }
    return tree;
}

void printTree(treeNode t)
{
    t.treeNode::printTree(t);
}