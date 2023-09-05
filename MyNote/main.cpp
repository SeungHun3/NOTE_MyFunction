#include <iostream>
#include <vector>
#include"MyFunction.h"
#include <regex>
using namespace std;


int main() {

    MyFunction* repo = new MyFunction;

    string myOrigin = "nice to meet you";
    string myCheck = "aeiou";
    cout<<repo->MyRegex_Replace(myOrigin, myCheck);

    delete repo;
    return 0;
}