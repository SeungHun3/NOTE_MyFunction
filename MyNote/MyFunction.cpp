#include "MyFunction.h"
#include <regex>
#include <queue>
#include <algorithm>
#include <map>

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
                break; // 이미 삭제해야 할 문자를 찾았으므로 내부 루프 종료
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
    //아스키코드 a = 97 ~ z = 122, A = 65 ~ Z = 90 // 32차이
    if (str.empty()) { return string(); }
    
    for (int i = 0; i < input.size(); i++) // 모두 소문자로 바꾼 후
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
    // 문자열을 공백을 기준으로 단어로 나누기
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
    words.push_back(word); // 마지막 단어 추가
    
    return words;
}
//toupper 대문자변환 ,  tolower 소문자변환
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
    //사용법
    /*

    [=] () {} () // 모든 외부 변수 result1, result2, result3, result4를 복사해서 람다 함수 내부에서 사용
    [&] () {} () // 모든 외부 변수 result1, result2, result3, result4 를 참조해서 람다 함수 내부에서 사용
    [&, result3] () {} () // 모든 외부 변수 (result1,2,4)은 참조로 사용하지만, result3만 복사로 사용
    [=, &result3] () {} () // 모든 외부 변수 (result1,2,4)은 복사로 사용하지만, result3만 참조로 사용

    */


    string mystring = str;

    [mystring]()mutable { // 외부변수 받아와 값사용
        mystring = "===";   // mutable 키워드로 수정할수 있게 열어줌
        cout << mystring << endl; // 함수내에서 변경됨
    }();
    cout << mystring << endl; // 하지만 참조변수가 아닌 복사변수를 사용하므로 직접적인 값은 변경되지 않음 // 지역변수를 가져올때 주로 사용


    [&]() {              // 모든 외부변수 참조값으로 받아와 값 변경
        mystring = "aaa";

    }();
    cout << mystring << endl;


    [&mystring]() { // 외부변수를 특정해 참조값으로 받아옴
        mystring = "bbb";

    }();
    cout << mystring << endl;



    [&, mystring]()mutable {    // 모든 외부변수를 참조로 가져옴, 외부변수를 지정해서 복사로 가져옴
        mystring = "ccc";       // 이 경우 지정된 변수는 복사로 할당되니 mutable 키워드로 열어줌

    }();
    cout << mystring << endl; // 모든 외부변수가 참조형태로 들어왔으니 값은 변경됨 => 의도가 명확하지 않다면 잘 못 사용된 형태임

    //==> 이렇게 사용하는 이유는 외부변수가 지역변수일때 참조한 메모리가 쓸모없어지게됨
    // 결국 지정해서 값을 받아와 람다내에 저장 후 외부변수에 넘겨주는 형태로 가져가는게 사용 의도임




    [=, &mystring]() {   // 모든 외부변수  복사로 받아옴, 외부변수 지정해 참조로 받아옴
        mystring = "ddd";

    }();
    cout << mystring << endl; // 지정된 값이 참조형태이니 값이 변경됨


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

void MyFunction::MyMap(string key, int value)
{
    map<string, int> myMap;
    for (int i = 0; i < value; i++)
    {
        myMap[key] = value;
    }
    cout << myMap.size(); // key와 value가 중복없이 설정
}


#include<bitset>

char MyFunction::bitsToChar(const std::string& bitString)
{


    // 동적으로 std::bitset 생성
    std::bitset<64> mybitset(bitString); // 여기에서 64는 임의의 충분히 큰 값

    // 이진수를 정수로 변환
    int value = mybitset.to_ulong();
    // 64개의 비트를 스트링으로 표현
    string str = mybitset.to_string();

    // 정수를 문자로 변환
    return static_cast<char>('A' + value);

    // bitset 사용법
    {
        int iBit = 0b1011;

        std::bitset<64> imybitset(iBit);
        int iValue = imybitset.to_ulong();
        string strValue = imybitset.to_string();

    }
    
    {
        string strBit = "01111";

        std::bitset<64> str_mybitset(strBit);
        int iTemp = str_mybitset.to_ulong();
        string strTemp = str_mybitset.to_string();
    }

    //bit set  모든 함수
    {
        string strBit = "01111";

        std::bitset<64> str_mybitset(strBit);
        // bitset을 선언, 총 64개의 비트를 의미한다. 
        // 전체 비트를 0으로 리셋한다.    
        str_mybitset.reset();
        // 전체 비트를 1로 셋팅한다.    
        str_mybitset.set();
        // 비트셋으로 선언한 bit의 할당된 수를 구한다    
        int mysize;
        mysize = (int)str_mybitset.size();
        // 비트셋중 하나라도 1이면 1을 반환, 모두 0이면 0을 반환한다.    
        // 현재는 bit.set()로 인해 모두 1이다.   
        // 0으로 리셋    
        str_mybitset.reset();
        // 현재는 0으로 모두 리셋이 되었으니 0이 출력된다.   
        // 4번째 비트 반전   
        str_mybitset.flip(3);
        // 하나라도 1이면 bit.any()는 1이되니 bit.none()는 0이된다. 
        // 현재 비트 구성 확인    
        // 첫번째 비트는 true, 네번째 비트는 false 할당    
        str_mybitset.set(0, true);
        str_mybitset.set(3, false);
        // 첫번째 비트 검사    
        str_mybitset.test(0);
        // 다섯번째 비트 검사(배열형식으로도 가능하다.)    
        str_mybitset[4];
        // 현재 비트 출력    
        str_mybitset;
        // 모든 비트 반전    
        str_mybitset.flip();
        // 비트를 string으로 변환    
        string str = str_mybitset.to_string();
        // 비트를 숫자로 변환    
        str_mybitset.to_ulong();

    }



}
