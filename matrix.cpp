#include "matrix.h"

using namespace std;

int getLICSSize (vector<int> a, vector<int> b)
{
    size_t n = a.size();
    size_t m = b.size();
    int matrix[n+1][m+1];
    int last_numb = 0;

    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (a[i-1] == b[j-1] && a[i-1] > last_numb) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
                last_numb = a[i-1];
            }
            else if (matrix[i-1][j] >= matrix[i][j-1])
                matrix[i][j] = matrix[i-1][j];
            else
                matrix[i][j] = matrix[i][j-1];
        }
    }
    return matrix[n][m];
}
