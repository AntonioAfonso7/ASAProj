#include "tree.h"

void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr)
{
    if (t.getSons().size() == 0)
    {
        curArr.push_back(t.getValue());
        dest.push_back(curArr);
    }
    else if (t.isRoot())  // The node we are currently in is the root
    {
        std::vector<int> tmp(curArr);
        dest.push_back(tmp);
        for (size_t i = 0; i < t.getSons().size(); i++)
        {
            getAllVectors(t.getSons()[i], dest, tmp);
        }
    }
    
    else                // The node we are currently in is not the root
    {
        std::vector<int> tmp(curArr);
        tmp.push_back(t.getValue());
        dest.push_back(tmp);
        for (size_t i = 0; i < t.getSons().size(); i++)
        {
            getAllVectors(t.getSons()[i], dest, tmp);
        }
    }
}

void getLongestVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr)
{
    if (t.getSons().size() == 0)
    {
        curArr.push_back(t.getValue());
        dest.push_back(curArr);
    }
    else if (!t.isRoot())   // When the node we are currently in is not the root
    {
        for (size_t i = 0; i < t.getSons().size(); i++)
        {
            std::vector<int> tmp(curArr);
            tmp.push_back(t.getValue());
            getLongestVectors(t.getSons()[i], dest, tmp);
        }
    }
    
    else                    // When the node we are currently in is the root
    {
        std::vector<int> tmp(curArr);
        for(size_t i = 0; i < t.getSons().size(); i++)
        {  
            std::cout << "ola";
            getLongestVectors(t.getSons()[i], dest, tmp);
        }
    }
}

void filterMax(std::vector<std::vector<int> > &table)
{
    std::vector<std::vector<int> > tmp;
    size_t max_size = table[0].size();

    for (size_t i = 0; i < table.size(); i++)
    {
        if (table[i].size() > max_size)
        {
            max_size = table[i].size();
        }
    }

    for (size_t i = 0; i < table.size(); i++)
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
    treeNode tree(0, true); //Creates a tree node that will be the root

    for (size_t i = 0; i < v.size(); i++)
    {
        tree.treeNode::insert(tree, v[i]);
    }
    return tree;
}

void printTree(treeNode t)
{
    t.treeNode::printTree(t);
}
