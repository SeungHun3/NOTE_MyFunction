#include "MyFunction.h"


bool MyFunction::isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

string MyFunction::eraseStr(string origin, string checklist)
{
    for (int i = 0; i < origin.size(); i++)
    {
        for (int j = 0; j < checklist.size(); j++)
        {
            if (origin[i] == checklist[j])
            {
                origin.erase(i, 1);
            }
        }
    }
    return origin;
}
