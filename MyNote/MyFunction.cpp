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
    string result = "";

    for (int i = 0; i < origin.size(); i++) {
        bool shouldErase = false;

        for (int j = 0; j < checklist.size(); j++) {
            if (origin[i] == checklist[j]) {
                shouldErase = true;
                break; // 이미 삭제해야 할 문자를 찾았으므로 내부 루프 종료
            }
        }

        if (!shouldErase) {
            result += origin[i];
        }
    }

    return result;
}
