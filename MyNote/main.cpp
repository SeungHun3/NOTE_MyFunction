#include <iostream>
#include"MyFunction.h"

using namespace std;
\
int main() {

    MyFunction* repo = new MyFunction;
    string mystr = "forEachLoop//";
    repo->MyForEachLoop(mystr);
    repo->MyLambda("abcd");
    delete repo;
    return 0;
}