#pragma once
#include<iostream>
#include<vector>

using namespace std;


class MyFunction
{
public:
    //소수 인지 확인하는 함수
    bool isPrime(int n);
    //string erase
    string eraseStr(string origin, string checklist);
    //string regex_replace
    string MyRegex_Replace(string origin,const string& checklist);

    string JadenCase(string str);
    vector<string> Parsing(string str);

    string makeJaden(string str);

    bool queue_checkCorrect(string str);

    void MyForEachLoop(string str);

    void MyLambda(string str);

    int MakeDecimal(int var);

    vector<int> MyFibonacci(int count);

    void MyMap(string key, int value);

};