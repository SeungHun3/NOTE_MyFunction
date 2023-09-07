#include <iostream>
#include"MyFunction.h"

using namespace std;

int main() {

    MyFunction* repo = new MyFunction;
    string mystr = "my teSt CASe";
    string myResult = "";
    for (auto it : repo->Parsing(mystr))
    {
        myResult += repo->makeJaden(it);
    }
    cout << myResult;
    delete repo;
    return 0;
}