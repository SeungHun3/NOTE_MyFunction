#include "programmers.h"
#include <set>
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
    bool answer = true;




    return answer;
}
