#include <iostream>
#include <vector>
#include <string>


class treeNode
{
private:
    int value;
    std::vector<treeNode> sons;
public:
    treeNode(int n) {
        value = n;
    }
    treeNode insert(treeNode t, int n);
};

treeNode treeNode::insert(treeNode t, int n) {
    if (t.sons.size() == 0) {
        t.sons.push_back(treeNode(n));
        return t;
    }
    else {
        for(int i = 0; i < t.sons.size(); i++) {
            if (t.sons[i].value < n) {
                t.sons[i] = insert(t.sons[i], n);
            }
        }
        return t;
    }
}






std::vector<int> subVector(std::vector<int> v, int begin, int end) {
    std::vector<int> res;

    for(int i = begin; i < end; i++) {
        res.push_back(v[i]);
    }

    return res;
}

std::vector<int> readVector() {
    char token;
    std::vector<int> v;
 
    getchar();
    while((token = getchar()) != EOF) { 
        if( token == '\n') {break;}  
        if (token != ' ') 
            v.push_back((int)token);
    }
    return v;
}

std::string printVector(std::vector<int> vector) {
    std::string out;

    for (int i = 0; i < vector.size(); i++) {
        out.push_back(i);
        out.push_back(',');
        out.push_back(' ');
    }

    return out.substr(0, out.size()-2);
}



std::vector<int> getSequence(std::vector<int> v) {
    treeNode tree(v[0]);

    for (int i = 1; i < v.size(); i++) {
        tree = tree.insert(tree, v[i]);
    }
}

int main() {
    int option;

    std::cin >> option;
    std::vector<int> v;

    if (option == 1) {
       v = readVector(); 
    }

    std::cout << printVector(v) << std::endl;

    return 0;
}