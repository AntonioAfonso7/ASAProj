#include <iostream>
#include <vector>
#include <string>

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

    for (int i : vector) {
        out.push_back(i);
        out.push_back(',');
        out.push_back(' ');
    }

    return out.substr(0, out.size()-2);
}

std::vector<int> getSequence(std::vector<int> v, std::vector<int> res) {
    if ( v.size() == 0) {
        return res;
    } if ( res.size() == 0) {
        res.push_back(v[0]);
        return getSequence(subVector(v, 1, v.size()), res);
    } else if ( v[0] >= res[res.size() - 1]) {
        res.push_back(v[0]);
        return getSequence(subVector(v, 1, v.size()), res);
    } else {
        int i = res.size()-1;
        while(v[0] < res[i]) {
            i--;
        }
        
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