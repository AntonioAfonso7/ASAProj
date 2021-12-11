#include "treeNode.h"

treeNode::treeNode(int n)
{
    setValue(n);
    root = false;
}

treeNode::treeNode(int n, bool b)
{
    setValue(n);
    root = b;
}

bool treeNode::isRoot()
{
    return root;
}

void treeNode::setValue(int n)
{
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

    for (size_t i = 0; i < sons.size(); i++)
    {
        std::cout << sons[i].value << " | ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < sons.size(); i++)
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
        for (size_t i = 0; i < t.sons.size(); i++)
        {
            if (t.sons[i].value < n)
            {
                t.sons[i].insert(t.sons[i], n);
            }
        }
        t.sons.push_back(treeNode(n));
    }
}

void treeNode::printTree(treeNode t)
{
    if (t.sons.empty())
    {
        std::cout << t.value << " ";
    }
    else
    {
        std::cout << t.value << "-> ";
        for (size_t i = 0; i < t.sons.size(); i++)
        {
            std::cout << t.sons[i].value << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < t.sons.size(); i++)
        {
            printTree(t.sons[i]);
        }
    }
}
