#include "tree.h"

std::vector<int> readVector(std::vector<int> &v, std::string input)
{
    int token = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
        {
            token = token * 10;
            token += (input[i] - 48);
        }
        else
        {
            v.push_back(token);
            token = 0;
        }
    }
    if (token != 0)
    {
        v.push_back(token);
    }

    return v;
}

void printVector(std::vector<int> vector)
{
    std::string out;

    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i];
        std::cout << ',';
        std::cout << ' ';
    }

    std::cout << std::endl;
}


int main()
{
    int option;

    char opt;
    opt = getchar();
    option = opt - 48;
    getchar();

    std::vector<int> v;

    if (option == 1)
    {
        std::string input;
        getline(std::cin, input);
        readVector(v, input);

        treeNode tree = getTree(v);

        std::vector<std::vector<int> > table;
        std::vector<int> empty;

        getAllVectors(tree, table, empty);
        filterMax(table);

        int number_seq = table.size();
        int size_seq = table[0].size();

        std::cout << size_seq << " " << number_seq << std::endl;
    }

    return 0;
}
