#include <iostream>
#include "programmers.h"

using namespace std;

int main() {

    programmers* repo = new programmers;
    vector<int>a = { 1,2,4,5,7,5,6,7,4,3 };
    cout << repo->���ϸ�(a) << endl;
    cout << "==========================" << endl;

    vector<string> participant = { "a","b","c","d","e","f","g" };
    vector<string> completion = { "a","b","c","d","e","g" };
    cout << repo->�����������Ѽ���(participant, completion) << endl;
    cout << "==========================" << endl;

    vector<string> phone_book = { "124","112412","55576641","124214" };
    repo->��ȭ��ȣ���(phone_book);
    cout << "==========================" << endl;

    vector<vector<string>> cloth = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"}, { "green_turban", "headgear" },{"blue_sunglasses", "eyewear"} ,{"blue_sunglasses", "eyewear"} ,{"blue_sunglasses", "under"},{"blue_sunglasses", "under"},{"blue_sunglasses", "under"},{"blue_sunglasses", "under"}};
    repo->�ǻ�(cloth);

    delete repo;
    return 0;
}