#include <iostream>
#include"MyFunction.h"

using namespace std;
\
int main() {

    MyFunction* repo = new MyFunction;
    int count = 10;
    vector<int> fibonacci = repo->MyFibonacci(count);
    for(auto it : fibonacci)
    {
        cout << it << endl;
    }

    delete repo;
    return 0;
}