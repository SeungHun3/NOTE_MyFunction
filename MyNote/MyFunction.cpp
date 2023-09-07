#include "MyFunction.h"
#include <regex>

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
