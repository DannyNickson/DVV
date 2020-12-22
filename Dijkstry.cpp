#include <iostream>
#include <stdlib.h>
#define SIZE 6
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int a[SIZE][SIZE];
    int d[SIZE]; 
    int v[SIZE];
    int temp, minindex, min;
    int begin_index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            cout << "Введите расстояние " << i + 1 << "-" << j + 1<<":";
            cin >> temp;
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
           cout<<a[i][j]<<" ";
        cout << endl;
    }
    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { 
            if ((v[i] == 1) && (d[i] < min))
            { 
                min = d[i];
                minindex = i;
            }
        }
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    cout << "\nКратчайшие расстояния до вершин: \n";
    for (int i = 0; i < SIZE; i++)
        cout << d[i] << " ";
    int ver[SIZE]; 
    int end = 4; 
    ver[0] = end + 1; 
    int k = 1; 
    int weight = d[end]; 

    while (end != begin_index) 
    {
        for (int i = 0; i < SIZE; i++) 
            if (a[i][end] != 0)  
            {
                int temp = weight - a[i][end]; 
                if (temp == d[i]) 
                {                 
                    weight = temp; 
                    end = i;    
                    ver[k] = i + 1; 
                    k++;
                }
            }
    }
    cout << "\nВывод кратчайшего пути\n";
    for (int i = k - 1; i >= 0; i--)
        cout << ver[i] << " ";
    return 0;
}