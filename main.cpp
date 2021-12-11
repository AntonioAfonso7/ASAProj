#include "tree.h"

std::vector<int> readVector(std::vector<int> &v, std::string input)
{
    int n;

    std::istringstream c(input);

    while (c >> n)
    {
        v.push_back(n);
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
    std::string option_line;

    std::getline(std::cin, option_line);
    option = option_line[0] - 48; // ascii conversion to int

    std::vector<int> v;
    std::vector<int> v1;
    std::vector<int> v2;

    if (option == 1)
    {
        std::string input;
        getline(std::cin, input);
        readVector(v, input);

        treeNode tree = getTree(v);

        std::vector<std::vector<int> > table;
        std::vector<int> empty;

        getLongestVectors(tree, table, empty);
        filterMax(table);

        int number_seq = table.size();
        int size_seq = table[0].size();

        std::cout << size_seq << " " << number_seq << std::endl;
    }

    if (option == 2)
    {
        int nsize = 0;
        std::string input1;
        std::string input2;
        getline(std::cin, input1);
        getline(std::cin, input2);

        readVector(v1, input1);
        readVector(v2, input2);

        treeNode t1 = getTree(v1);
        treeNode t2 = getTree(v2);

        std::vector<std::vector<int> > vfinal;
        std::vector<std::vector<int> > table1;
        std::vector<std::vector<int> > table2;

        std::vector<int> empty1;
        std::vector<int> empty2;

        getAllVectors(t1, table1, empty1);
        getAllVectors(t2, table2, empty2);

        int number_seq1 = table1.size();
        int number_seq2 = table2.size();

        for (int i = 0; i < number_seq1; i++)
        {
            for (int j = 0; j < number_seq2; j++)
            {
                if (table2[j] == table1[i])
                    vfinal.push_back(table1[i]);
            }
        }

        if (vfinal.size() == 0)
        {
            std::cout << "0" << std::endl;
        }

        nsize = vfinal[0].size();
        for (int i = 1; i < vfinal.size(); i++)
        {
            if (vfinal[i].size() > nsize)
            {
                nsize = vfinal[i].size();
            }
        }
        std::cout << nsize << std::endl;
    }

    return 0;
}
