#include "programmers.h"
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int programmers::���ϸ�(vector<int> nums)
{
    // ���� ���� ���� ã��
    int answer = 0;
    
    set<int> uniqueNums(nums.begin(), nums.end());
    //nums.erase(unique(nums.begin(), nums.end()), nums.end());�� ����
    // unique(nums.begin(), nums.end()); => �ߺ����� ���� ���� �� // ���� �ڸ��� ���� �迭�� ������

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

string programmers::�����������Ѽ���(vector<string> participant, vector<string> completion)
{
    // ��� ������ �� 1�� �������� ����
    // ��� ������ �̸� �־���, ������ �̸� �־���
    string answer = "";
    map<string,int > check;
    // ������ ����� map�� �߰�
    for (const string& parti_person : participant)
    {
        check[parti_person]++; // �ʿ� Ű��, 1�� �־���
    }
    // ������ ������ map���� ����
    for (const string& comp_person : completion)
    {
        check[comp_person]--; // �ʿ� Ű�� value �� 0���� ����
    }

    for (const auto& pair : check)  // 1�� value�� ã��
    {
        if (pair.second > 0) {
            answer = pair.first;
            break;
        }
    }


    // �ٸ���� Ǯ�� 

    /*
    **���� �� ��
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

bool programmers::��ȭ��ȣ���(vector<string> phone_book)
{
    bool answer = true;




    return answer;
}
