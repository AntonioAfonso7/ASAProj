#include "tree.h"

void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr)
{
    if (t.getSons().size() == 0)
    {
        curArr.push_back(t.getValue());
        dest.push_back(curArr);
    }
    else if (t.getValue() == 0)
    {
        std::vector<int> tmp(curArr);
        dest.push_back(tmp);
        for (size_t i = 0; i < t.getSons().size(); i++)
        {
            getAllVectors(t.getSons()[i], dest, tmp);
        }
    }
    
    else
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
    else if (t.getValue() == 0)
    {
        std::vector<int> tmp(curArr);
        for (size_t i = 0; i < t.getSons().size(); i++)
        {
            getLongestVectors(t.getSons()[i], dest, tmp);
        }
    }
    
    else
    {
        for(size_t i = 0; i < t.getSons().size(); i++)
        {
            std::vector<int> tmp(curArr);
            tmp.push_back(t.getValue());
            getLongestVectors(t.getSons()[i], dest, tmp);
        }
    }
}

void filterMax(std::vector<std::vector<int> > &table)
{
    std::vector<std::vector<int> > tmp;
    size_t max_size = table[0].size(); // By the algorithm we know the first vector is the biggest

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
    int negative_infinity = -std::numeric_limits<int>::infinity();
    treeNode tree(negative_infinity);

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
