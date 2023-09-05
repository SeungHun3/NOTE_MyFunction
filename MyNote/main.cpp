#include <iostream>
#include <vector>
#include"MyFunction.h"
using namespace std;


int main() {

    vector<int> push;
    int i = 1;
    int sum = 0;

    while (1)
    {
        if (isPrime(i))
        {
            sum += i;
            if (sum > 4000000)
            {
                break;
            }
            push.push_back(i);

        }
        i++;
    }
    for (auto it : push)
    {
        cout << it;
    }

    return 0;
}