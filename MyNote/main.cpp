#include <iostream>
#include "programmers.h"

using namespace std;

int main() {

    programmers* repo = new programmers;
    vector<int>a = { 1,2,4,5,7,5,6,7,4,3 };
    cout<<repo->���ϸ�(a);

    vector<string> participant = { "a","b","c","d","e","f","g" };
    vector<string> completion = { "a","b","c","d","e","g" };
    cout << repo->�����������Ѽ���(participant, completion);

    delete repo;
    return 0;
}