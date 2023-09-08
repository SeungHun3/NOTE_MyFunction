#include <iostream>
#include"MyFunction.h"

using namespace std;
\
int main() {

    MyFunction* repo = new MyFunction;
    repo->MyMap("Seunghun", 10);
    delete repo;
    return 0;
}