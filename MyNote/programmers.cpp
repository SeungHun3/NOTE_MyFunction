#include "programmers.h"
#include <string>
#include <set>
#include <unordered_set>
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

    //��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, 
    //� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� 
    // �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

    // vector<string> ����->���� �������� ����
    sort(phone_book.begin(), phone_book.end(), [](const string& a, const string& b) {
        return stoi(a) < stoi(b);
        });
    
    set<string> table;        //set�� hash�� �ҷ��ͼ� �˾Ƽ� string�� �ؽ� ó��
    size_t min = 0xFFFFFFFF;  // size_t(unsigned int)�� ����Ͽ� 8����Ʈ ���� �ڷ����� �ִ밪���� �ʱ�ȭ 

    for (string phone : phone_book)
    {
        if (!table.empty())
        {
            //�ּ� ������ ���ڿ����͸� ó���Ͽ� ���� ���̱�(i = min)
            for (int i = min; i <= phone.size(); ++i)
            {
                //���ڿ��� �߶� Ž�� (+�˾Ƽ� �ؽ� ó��)
                string key = phone.substr(0, i);
                if (table.find(key) != table.end())
                {
                    return false;
                }
            }
        }

        //���ο� ��� ���ڿ��� set�� �߰�. ���̺��� ���� ����Ͽ� Ű���� �ߺ��Ǵ� �̽��� ����
        table.insert(phone);

        //���ڿ� ������ �ּҰ� ���� 
        if (phone.size() < min)
        {
            min = phone.size();
        }
    }


    return true;
}

int programmers::�ǻ�(vector<vector<string>> clothes)
{
    int answer = 0;
    // ex) 0, 1, 2 �� �����Ѵٸ� 
    // 0, 0*1, 0*2, 0*1*2, 
    // 1, 1*2, 
    // 2 
    // �� ���չ���� ����ؾ���


    map<string,int> checkName;
    // �켱 �ʿ� ������ ������ ���� ���� ����
    for (vector<string> type : clothes)
    {
        checkName[type[1]]++;
    }
    vector<int> originArray;
    for (auto it : checkName)
    {
        originArray.push_back(it.second);
    }
    // ����ó��
    if (originArray.size() <= 0)
        return 0;

    int sum = 1;

    // ���� ��� ���н� 
    // �� 2 �Ӹ� 1 ���� 5 => ��(2+1) * �Ӹ�(1+1) * ����(5+1) - 1
    vector<int> changedArray;
    for (int i = 0; i < originArray.size(); i++) // �� ������ �� +1 
    {
        changedArray.push_back(originArray[i] + 1);
    }
    
    for (auto it : changedArray)
    {
        sum *= it; // �� ������ �� ��� ���ϱ�
    }
    answer = sum - 1; // ������ 1 ����


    return answer;
}

int programmers::�ǻ�_�ٸ����Ǯ��(vector<vector<string>> clothes)
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
