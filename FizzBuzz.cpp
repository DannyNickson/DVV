#include <iostream>
#include <string>
int main()
{
    int i = 1;
    while (i < 101)
    {
        std::string n = std::to_string(i), f = "Fizz", b = "Buzz";
        if (i % 3 != 0) f = ""; else n = "";
        if (i % 5 != 0) b = ""; else n = "";
        std::cout << n + f + b + "\n";
        i++;
    }
}
