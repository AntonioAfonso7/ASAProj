#include "treeNode.h"

treeNode::treeNode(int n)
{
    setValue(n);
}

void treeNode::setValue(int n) {
    value = n;
}

int treeNode::getValue()
{
    return value;
}

std::vector<treeNode> treeNode::getSons()
{
    return sons;
}

void treeNode::print()
{
    std::cout << value << " -> ";

    for (int i = 0; i < sons.size(); i++)
    {
        std::cout << sons[i].value << " | ";
    }
    std::cout << std::endl;

    for (int i = 0; i < sons.size(); i++)
    {
        sons[i].print();
    }
}

void treeNode::insert(treeNode &t, int n)
{
    if (t.sons.size() == 0)
    {
        t.sons.push_back(treeNode(n));
    }
    else
    {
        for (int i = 0; i < t.sons.size(); i++)
        {
            if (t.sons[i].value < n)
            {
                t.sons[i].insert(t.sons[i], n);
            }
        }
        t.sons.push_back(treeNode(n));
    }
}