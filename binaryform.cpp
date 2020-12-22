#include <iostream>
#include <string>
int main() 
{
    int n;
    std::cin >> n;
    int nn = n;
    std::string result;
    do
    {
        result = (std::to_string((n % 2))) + result;
        n = n / 2;
    } while (n > 0);
    std::cout << result<<std::endl;
    int max = 0, min = 100, countone = 0, countone2 = 0;

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == '1')
        {
            countone++;
        }
    }
    std::string result2;
    int ii = 0;
    for (int i = 0; i <nn*nn; i++)
    {
        countone2 = 0;
        ii = i;
        do
        {
            result2 = (std::to_string((ii % 2))) + result2;
            ii = ii / 2;
        } while (ii > 0);
        for (int j = 0; j < result2.size(); j++)
        {
            if (result2[j] == '1')
            {
                countone2++;
            }
        }
        if (countone == countone2)
        {
            if (i > max)
            {
                max = i;
            }
            if (i<min)
            {
                min = i;
            }
        }
        result2.clear();
        countone2 = 0;
    }
    std::cout << "Max-" << max << std::endl;
    std::cout << "Min-" << min << std::endl;
    std::cout << "Result-" << result << std::endl;
}

