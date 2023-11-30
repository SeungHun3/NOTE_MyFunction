#include "programmers.h"
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <queue>
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
        answer = (int)count;
    }
    else 
    {
        answer = (int)uniqueNums.size();
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
            for (size_t i = min; i <= phone.size(); ++i)
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

vector<int> programmers::같은숫자는싫어(vector<int> arr)
{

    vector<int> answer;

    list<int> list;
    for (auto it : arr)
    {
        if (list.empty())
        {
            list.push_back(it);
        }
        else
        {
            if (list.back() != it)
            {
                list.push_back(it);
            }
        }
    }
    for (auto it : list)
    {
        answer.push_back(it);
    }

    return answer;
}

vector<int> programmers::기능개발(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> days;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int temp = (100 - progresses[i]);
        if (temp % speeds[i] == 0)
        {
            temp /= speeds[i];
        }
        else
        {
            temp = (temp / speeds[i]) + 1;
        }

        days.push_back(temp);
    }
    int max = days[0];
    // 3,2,3,5,4,5
    int count = 1;
    for (int i = 1; i < days.size(); ++i)
    {
        if (max >= days[i])
        {
            count++;
            if (i == (days.size() - 1))
            {
                answer.push_back(count);
            }
        }
        else
        {
            answer.push_back(count);
            max = days[i];
            count = 1;
            if (i == (days.size() - 1))
            {
                answer.push_back(count);
            }
        }

    }
    return answer;
}

int programmers::프로세스(vector<int> priorities, int location)
{
    int answer = 0;

    vector<int> sortarr = priorities;
    sort(sortarr.begin(), sortarr.end());
    list<int>dec;
    for (auto it : sortarr)
    {
        dec.push_front(it);
    }
    // 타겟 iterator 구하기
    int loc = location;
    list<int>::iterator targetIter;
    list<int> mylist;
    for (auto it : priorities)
    {
        mylist.push_back(it);
        if (loc == 0)
        {
            targetIter = prev(mylist.end());
        }
        --loc;
    }
    int count = 1;
    int decint = *dec.begin();
    while (1)
    {
        if (*dec.begin() == *mylist.begin())
        {
            if (mylist.begin() == targetIter)
            {
                break;
            }
            dec.pop_front();
            mylist.pop_front();
            count++;

        }
        else
        {
            mylist.splice(mylist.end(), mylist, mylist.begin());
        }

    }
    return count;
}

int programmers::다리를지나는트럭(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;// 시간
    int bridge = bridge_length;
    int bweight = weight;
    list<int> wait_trucks;
    list<int>going_trucks; // value = 무게,length = 현재 건너고 있는 시간

    for (auto it : truck_weights)
    {
        wait_trucks.push_back(it);
    }

    while (true)
    {

        answer++;

        // 트럭빼기
        if (bridge <= going_trucks.size())
        {
            going_trucks.pop_front();
        }

        int going_weight = 0;
        for (auto it : going_trucks)
        {
            going_weight += it;   // 무게 구해서
        }


        // 트럭 넣기 = 대기트럭 빼고 건너는 트럭에 넣기
        if (!wait_trucks.empty()) // 기다리는 트럭이 있다면
        {

            int start_Truck = wait_trucks.front();

            if (bweight >= start_Truck + going_weight) // 트럭이 갈 수 있을 때
            {
                going_weight += start_Truck;
                going_trucks.push_back(start_Truck);
                wait_trucks.pop_front();

            }
            else // 트럭이 갈 수 없을 때
            {
                going_trucks.push_back(0);
            }


        }
        else // 기다리는 트럭이 없다면
        {
            // 건너고 있는 트럭이 없다면
            if (going_weight == 0)
            {
                break;
            }
            going_trucks.push_back(0);
        }

    }

    return answer;
}

vector<int> programmers::주식가격(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); ++i)
    {
        int time = 0;
        for (int j = i + 1; j < prices.size(); ++j)
        {
            int target = prices[i];
            int compare = prices[j];
            time++;
            if (target > compare)
            {
                break;
            }
        }
        answer.push_back(time);
    }

    return answer;
}

int programmers::더맵게(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > scv(scoville.begin(), scoville.end());

    while (true)
    {
        // 모든 음식의 스코빌지수 k 이상 만들 수 없을때
        if (scv.size() <= 1 && scv.top() < K)
        {
            return -1;
        }
        if (scv.top() >= K)
            break;

        int first = scv.top();
        scv.pop();
        int second = scv.top();
        scv.pop();
        int shakeScv = first + (second * 2);

        scv.push(shakeScv);
        answer++;

    }
    return answer;
}

vector<int> programmers::이중우선순위큐(vector<string> operations)
{
    vector<int> answer;
    list<int> queue;
    while (!operations.empty())
    {
        string str = operations[0];
        operations.erase(operations.begin());
        // 삽입
        if (str[0] == 'I')
        {
            string substr = str.substr(2, str.size() - 2);
            int push = stoi(substr);
            queue.push_back(push);
        }

        //삭제
        else if (str[0] == 'D')
        {
            if (queue.empty())
                continue;

            string substr = str.substr(2, str.size() - 2);
            int push = stoi(substr);
            if (push > 0)
            {
                //최대값 삭제
                list<int>::iterator MaxIter = max_element(queue.begin(), queue.end());
                queue.erase(MaxIter);
            }
            else
            {
                // 최소값 삭제
                list<int>::iterator MinIter = min_element(queue.begin(), queue.end());
                queue.erase(MinIter);
            }
        }
    }
    if (queue.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    queue.sort();
    answer.push_back(queue.back());
    answer.push_back(queue.front());
    return answer;
}