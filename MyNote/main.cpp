#include <iostream>
#include"MyFunction.h"

using namespace std;
\
int main() {

    MyFunction* repo = new MyFunction;
    int var = 110;
    cout << repo->MakeDecimal(var);
    delete repo;
    return 0;
}