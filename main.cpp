#include "tree.h"
#include <string>
#include <iostream>

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
    int count = 0; 
    std::string option_line;
    char opt;


    std::getline(std::cin, option_line);
    option = option_line[0] - 48;  // ascii conversion to int

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

        getAllVectors(tree, table, empty);
        filterMax(table);

        int number_seq = table.size();
        int size_seq = table[0].size();

        std::cout << size_seq << " " << number_seq << std::endl;
    }

    if (option == 2)
    {
        bool success;
        bool first = true;
        int nsize = 0;
        int nvectors = 0;
        std::string input1;
        std::string input2;
        getline(std::cin, input1);
        getline(std::cin, input2);

        readVector(v1, input1);
        readVector(v2, input2);

        treeNode t1 = getTree(v1);
        treeNode t2 = getTree(v2);

        std::vector<std::vector<int> > table1;
        std::vector<std::vector<int> > table2;
        std::vector<std::vector<int> > vfinal;
        std::vector<int> empty1;
        std::vector<int> empty2;

        getAllVectors(t1, table1, empty1);
        getAllVectors(t2, table2, empty2);

        int number_seq1 = table1.size();
        int number_seq2 = table2.size();

        int size_seq1 = table1[0].size();
        int size_seq2 = table2[0].size();


        for (int i = 0; i < number_seq1; i++){
            for (int j = 0; j < number_seq2; j++){  
                success = true;
                if (table1[i].size() != table1[j].size()) break; // only equal if they have the same size

                for (int k = 0; k < table1[i].size(); k++) {
                    if (table1[i][k] != table2[j][k]) {success = false;}
                    if (! success) break;
                    
                }
            }
            if (success) vfinal.push_back(table1[i]);
        }
        std::cout << "size: " << vfinal.size() << std::endl << "------------------" << std::endl;
        for (int i = 0; i < vfinal.size(); i++){
            for (int j = 0; j < vfinal[i].size(); j++)
                std::cout << vfinal[i][j] << " ";
            std::cout << std::endl;
        }                
 
        if (vfinal.size() == 0){
            std::cout << "0 0" << std::endl; 
        }

        for (int i = 0; i < vfinal.size(); i++){
            if (first) nsize = vfinal[0].size();
            first = false;
            if (vfinal[i].size() == nsize) nvectors++;
            if (vfinal[i].size() > nsize) {
                nsize = vfinal[i].size();
                nvectors = 1; // back to default 1
            }

        }
        std::cout << "------------------" << std::endl << nsize << " " << nvectors << std::endl;

    
    }

    return 0;
}

// for (int i = 0; i < number_seq1; i++){
 //           for (int j = 0; j < table1[i].size(); j++){  
   //             std::cout << table1[i][j] << " ";
     //       }
            
      //      std::cout << std::endl;
        //}
