#include <iostream>
#include"MyFunction.h"

using namespace std;

int main() {

    MyFunction* repo = new MyFunction;
    /*
    string myStr = "";
    std::vector<string>parseStr = repo->Parsing("3people unFollowed me");
    for (auto it : parseStr)
    {
        myStr += repo->JadenCase(it);
    }
    cout << myStr;
    */

    repo->JadenCase("amGad");
    delete repo;
    return 0;
}