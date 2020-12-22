#include <iostream>
using namespace std;

int main()
{
    int value_size = 4;
    int backpack_size = 7;
    int* values = new int[value_size] {16,19,23,28};
    int* weights = new int[value_size] {2, 3, 4, 5};
    int** matrix;
    matrix = new int* [backpack_size];
    for (int i = 0; i < backpack_size; i++)
    {
        matrix[i] = new int[value_size];
        matrix[i][0] = 0;
    }
    for (int j = 1; j < value_size; j++)
    {
        for (int i = 0; i < backpack_size; i++)
        {
            if (weights[j - 1] > i)
            {
               matrix[i][j] = matrix[i][j - 1];
            }
            else
            {
                int k = i - weights[j - 1];
                matrix[i][j] = max(matrix[i][j - 1], values[j - 1] +matrix[k][j - 1]);
            }
        }
    }
    for (int i = 0; i < backpack_size; i++)
    {
        for (int j = 0; j < value_size; j++)
        {
            cout <<matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int i = backpack_size - 1, j = value_size - 1;
    while (i != 0)
    {
        if (matrix[i][j] == matrix[i][j - 1])
        {
            cout << j << " Item is not taken" << endl;
        }
        else
        {
            cout << j << " Item is taken" << endl;
            i = i - weights[j - 1];
        }
        j--;
    }
    return 0;
}