#include "programmers.h"
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

int programmers::폰켓몬(vector<int> nums)
{
    // 가장 많은 종류 찾기
    int answer = 0;
    
    set<int> uniqueNums(nums.begin(), nums.end());
    //nums.erase(unique(nums.begin(), nums.end()), nums.end());도 가능
    // unique(nums.begin(), nums.end()); => 중복문자 없이 정렬 후 // 남는 자리엔 기존 배열의 값존재

    size_t count = nums.size() / 2;

    if (uniqueNums.size() > count) 
    {
        answer = count;
    }
    else 
    {
        answer = uniqueNums.size();
    }
   
    return answer;
}

string programmers::완주하지못한선수(vector<string> participant, vector<string> completion)
{
    // 모든 참가자 중 1명만 완주하지 못함
    // 모든 참가자 이름 주어짐, 완주자 이름 주어짐
    string answer = "";
    map<string,int > check;
    // 참가자 명단을 map에 추가
    for (const string& parti_person : participant)
    {
        check[parti_person]++; // 맵에 키와, 1을 넣어줌
    }
    // 완주한 선수를 map에서 제거
    for (const string& comp_person : completion)
    {
        check[comp_person]--; // 맵에 키의 value 에 0으로 줄임
    }

    for (const auto& pair : check)  // 1인 value를 찾기
    {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }


    // 다른사람 풀이 

    /*
    **정렬 후 비교
    * 
     sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];    
    */


    return answer;
}

bool programmers::전화번호목록(vector<string> phone_book)
{

    //전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 
    //어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 
    // 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

    // vector<string> 문자->숫자 내림차순 정렬
    sort(phone_book.begin(), phone_book.end(), [](const string& a, const string& b) {
        return stoi(a) < stoi(b);
        });
    
    set<string> table;        //set이 hash를 불러와서 알아서 string을 해시 처리
    size_t min = 0xFFFFFFFF;  // size_t(unsigned int)를 사용하여 8바이트 정수 자료형의 최대값으로 초기화 

    for (string phone : phone_book)
    {
        if (!table.empty())
        {
            //최소 길이의 문자열부터만 처리하여 연산 줄이기(i = min)
            for (int i = min; i <= phone.size(); ++i)
            {
                //문자열을 잘라서 탐색 (+알아서 해시 처리)
                string key = phone.substr(0, i);
                if (table.find(key) != table.end())
                {
                    return false;
                }
            }
        }

        //새로운 멤버 문자열을 set에 추가. 테이블을 먼저 등록하여 키값이 중복되는 이슈도 없음
        table.insert(phone);

        //문자열 길이의 최소값 갱신 
        if (phone.size() < min)
        {
            min = phone.size();
        }
    }


    return true;
}

int programmers::의상(vector<vector<string>> clothes)
{
    int answer = 0;
    // ex) 0, 1, 2 가 존재한다면 
    // 0, 0*1, 0*2, 0*1*2, 
    // 1, 1*2, 
    // 2 
    // 의 조합방법을 사용해야함


    map<string,int> checkName;
    // 우선 맵에 아이템 종류별 갯수 넣은 다음
    for (vector<string> type : clothes)
    {
        checkName[type[1]]++;
    }
    vector<int> originArray;
    for (auto it : checkName)
    {
        originArray.push_back(it.second);
    }
    // 예외처리
    if (originArray.size() <= 0)
        return 0;

    int sum = 1;

    // 조합 방법 수학식 
    // 옷 2 머리 1 바지 5 => 옷(2+1) * 머리(1+1) * 바지(5+1) - 1
    vector<int> changedArray;
    for (int i = 0; i < originArray.size(); i++) // 각 변수의 값 +1 
    {
        changedArray.push_back(originArray[i] + 1);
    }
    
    for (auto it : changedArray)
    {
        sum *= it; // 각 변수의 값 모두 곱하기
    }
    answer = sum - 1; // 마지막 1 빼기


    return answer;
}

int programmers::의상_다른사람풀이(vector<vector<string>> clothes)
{
    int answer = 1;

    map <string, int> attributes;
    for (int i = 0; i < clothes.size(); i++)
        attributes[clothes[i][1]]++;
    for (auto it = attributes.begin(); it != attributes.end(); it++)
        answer *= (it->second + 1);
    answer--;

    return answer;
}
