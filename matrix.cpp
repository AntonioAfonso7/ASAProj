#include "matrix.h"

using namespace std;

int getLICSSize (vector<int> a, vector<int> b)
{
    size_t a_size = a.size();
    size_t b_size = b.size();
    vector<vector<int> > matrix = vector<vector<int> >(a_size + 1, vector<int>(b_size + 1, 0));

    // Initialization of the matrix
    for (size_t i = 0; i < a_size; i++)
    {
        matrix[i][0] = 0;
    }
    for (size_t i = 0; i < b_size; i++)
    {
        matrix[0][i] = 0;
    }

    for (size_t i = 1; i < a_size; i++)
    {
        for (size_t j = 1; j < b_size; j++)
        {
            if (a[i-1] == b[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else if (matrix[i-1][j] >= matrix[i][j-1])
                matrix[i][j] = matrix[i-1][j];
            else
                matrix[i][j] = matrix[i][j-1];
        }
    }
    cout << matrix[a_size][b_size] << endl;
    return matrix[a_size][b_size];
}
