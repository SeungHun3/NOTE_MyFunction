#include <iostream>
#include"MyFunction.h"

using namespace std;

int main() {

    MyFunction* repo = new MyFunction;
    
    bool isCorrect = repo->queue_checkCorrect("()()");
    cout << isCorrect;
    delete repo;
    return 0;
}