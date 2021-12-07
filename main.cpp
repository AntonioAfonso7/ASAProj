#include <iostream>
#include <vector>
#include <string>

class treeNode
{
private:
    int value;
    std::vector<treeNode> sons;

public:
    treeNode(int n)
    {
        value = n;
    }
    void insert(treeNode &t, int n);
    std::vector<treeNode> getSons() { return sons; }
    int getValue() { return value; }
    void print();
};

void treeNode::print() {
    std::cout << value << " -> ";

    for(int i = 0; i < sons.size(); i++) {
        std::cout << sons[i].value << " | ";
    }
    std::cout << std::endl;

    for(int i = 0; i < sons.size(); i++) {
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

std::vector<int> subVector(std::vector<int> v, int begin, int end)
{
    std::vector<int> res;

    for (int i = begin; i < end; i++)
    {
        res.push_back(v[i]);
    }

    return res;
}

std::vector<int> readVector(std::vector<int> &v, std::string input)
{
    for(int i = 0; i < input.size(); i++) 
    {
        if (input[i] != ' ')
            v.push_back(input[i] - 48);
    }
    return v;
}

std::string printVector(std::vector<int> vector)
{
    std::string out;

    for (int i = 0; i < vector.size(); i++)
    {
        out.push_back(vector[i] + 48);
        out.push_back(',');
        out.push_back(' ');
    }

    return out.substr(0, out.size() - 2);
}

void getAllVectors(treeNode t, std::vector<std::vector<int> > &dest, std::vector<int> curArr)
{
    if (t.getSons().size() == 0)
    {
        curArr.push_back(t.getValue());
        dest.push_back(curArr);
    }
    else
    {
        for (int i = 0; i < t.getSons().size(); i++)
        {
            std::vector<int> tmp(curArr);
            tmp.push_back(t.getValue());
            getAllVectors(t.getSons()[i], dest, tmp);
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
        tree.insert(tree, v[i]);
    }
    return tree;
}

int main()
{
    int option = 1;

    std::vector<int> v;

    if (option == 1)
    {
        std::string input;
        getline(std::cin, input);

        // std::cout << input << std::endl;
        readVector(v, input);
        std::cout << "Vetor: " << printVector(v) << std::endl << std::endl << std::endl;

        treeNode tree = getTree(v);

        std::vector<std::vector<int> > table;
        std::vector<int> empty;

        getAllVectors(tree, table, empty);

        filterMax(table);

        for(int i = 0; i < table.size(); i++) {
            std::cout << printVector(table[i]) << std::endl;
        }
    }

    return 0;
}