#include "MyFunction.h"
#include <regex>
#include <queue>
#include <algorithm>
using namespace std;
bool MyFunction::isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

string MyFunction::eraseStr(string origin, string checklist)
{
    string result = "";

    for (int i = 0; i < origin.size(); i++) {
        bool shouldErase = false;

        for (int j = 0; j < checklist.size(); j++) {
            if (origin[i] == checklist[j]) {
                shouldErase = true;
                break; // �̹� �����ؾ� �� ���ڸ� ã�����Ƿ� ���� ���� ����
            }
        }

        if (!shouldErase) {
            result += origin[i];
        }
    }

    return result;
}

string MyFunction::MyRegex_Replace(string origin,const string& checklist)
{
    string result = "";
    string regexForm = "[]+";
    if (!origin.empty())
    {
        regexForm.insert(1, checklist);
    }
    result = regex_replace(origin, regex(regexForm), "");

    return result;
}

string MyFunction::JadenCase(string str)
{
    string input = str;
    string result;
    //�ƽ�Ű�ڵ� a = 97 ~ z = 122, A = 65 ~ Z = 90 // 32����
    if (str.empty()) { return string(); }
    
    for (int i = 0; i < input.size(); i++) // ��� �ҹ��ڷ� �ٲ� ��
    {
        if ((int)input[i] >= 65 && (int)input[i] <= 90)
        {
            char convert = static_cast<char>((int)input[i] + 32);
            result += convert;
        }
        else
        {
            result += input[i];
        }
    }
    if (((int)result[0] >= 97) && ((int)result[0] <= 122))
    {
        result[0] = static_cast<char>((int)result[0] - 32);
    }
    cout << result;
    return result;
}

vector<string> MyFunction::Parsing(string str)
{
    vector<string> words;
    string word = "";
    // ���ڿ��� ������ �������� �ܾ�� ������
    for (char c : str) 
    {
        if (c != ' ') 
        {
            word += c;
        }
        else 
        {
            word += ' ';
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word); // ������ �ܾ� �߰�
    
    return words;
}
//toupper �빮�ں�ȯ ,  tolower �ҹ��ں�ȯ
string MyFunction::makeJaden(string str)
{
    if (str.empty()) { return string(); }
    string input = str;
    string result = "";

    result += toupper(input[0]);
    for (int i = 1; i < input.size(); i++) 
    {
        result += tolower(input[i]);
    }

    return result;
}

bool MyFunction::queue_checkCorrect(string str)
{
    queue<char> myqueue;
    
    for (auto it : str)
    {
        switch (it)
        {
        case '(':
            myqueue.push('a');
            break;

        case ')':
            if (myqueue.empty())
            {
                cout << "false";
                return false;
            }
            myqueue.pop();
            break;
        }
    }
    if (myqueue.size() != 0)
    {
        return false;
    }

    return true;


}

void MyFunction::MyForEachLoop(string str)
{
    for_each(str.begin(),str.end(), [&](char& a) 
        {
            cout << a;
        });
    cout << endl;
}

void MyFunction::MyLambda(string str)
{
    //����
    /*

    [=] () {} () // ��� �ܺ� ���� result1, result2, result3, result4�� �����ؼ� ���� �Լ� ���ο��� ���
    [&] () {} () // ��� �ܺ� ���� result1, result2, result3, result4 �� �����ؼ� ���� �Լ� ���ο��� ���
    [&, result3] () {} () // ��� �ܺ� ���� (result1,2,4)�� ������ ���������, result3�� ����� ���
    [=, &result3] () {} () // ��� �ܺ� ���� (result1,2,4)�� ����� ���������, result3�� ������ ���

    */


    string mystring = str;

    [mystring]()mutable { // �ܺκ��� �޾ƿ� �����
        mystring = "===";   // mutable Ű����� �����Ҽ� �ְ� ������
        cout << mystring << endl; // �Լ������� �����
    }();
    cout << mystring << endl; // ������ ���������� �ƴ� ���纯���� ����ϹǷ� �������� ���� ������� ���� // ���������� �����ö� �ַ� ���


    [&]() {              // ��� �ܺκ��� ���������� �޾ƿ� �� ����
        mystring = "aaa";

    }();
    cout << mystring << endl;


    [&mystring]() { // �ܺκ����� Ư���� ���������� �޾ƿ�
        mystring = "bbb";

    }();
    cout << mystring << endl;



    [&, mystring]()mutable {    // ��� �ܺκ����� ������ ������, �ܺκ����� �����ؼ� ����� ������
        mystring = "ccc";       // �� ��� ������ ������ ����� �Ҵ�Ǵ� mutable Ű����� ������

    }();
    cout << mystring << endl; // ��� �ܺκ����� �������·� �������� ���� ����� => �ǵ��� ��Ȯ���� �ʴٸ� �� �� ���� ������

    //==> �̷��� ����ϴ� ������ �ܺκ����� ���������϶� ������ �޸𸮰� ����������Ե�
    // �ᱹ �����ؼ� ���� �޾ƿ� ���ٳ��� ���� �� �ܺκ����� �Ѱ��ִ� ���·� �������°� ��� �ǵ���




    [=, &mystring]() {   // ��� �ܺκ���  ����� �޾ƿ�, �ܺκ��� ������ ������ �޾ƿ�
        mystring = "ddd";

    }();
    cout << mystring << endl; // ������ ���� ���������̴� ���� �����


}

int MyFunction::MakeDecimal(int var)
{
    int myValue = var;
    if (myValue == 0)   {   return 0;}

    string convert = "";

    while (myValue >= 1)
    {
        int remainder = myValue % 2;
        convert += to_string(remainder);
        myValue /= 2;
    }
    
    reverse(convert.begin(), convert.end());
    int result = stoi(convert);

    return result;
}

vector<int> MyFunction::MyFibonacci(int count)
{
    vector<int> var;
    var.push_back(0);
    var.push_back(1);
    if (count < 3) { return var; }
    int myCount = count;
    for (int i = 0; i < myCount-2; i++)
    {
        unsigned int nextIndex = i + 1;
        var.push_back(var[i] + var[nextIndex]);
    }

    return var;
}
