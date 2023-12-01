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

vector<int> programmers::k번째수(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    while (!commands.empty())
    {
        vector<int>command = commands.front();
        commands.erase(commands.begin());
        vector<int> trimArray;
        for (int firstIdx = command[0] - 1; firstIdx < command[1]; firstIdx++)
        {
            trimArray.push_back(array[firstIdx]);
        }

        sort(trimArray.begin(), trimArray.end());
        answer.push_back(trimArray[command[2] - 1]);

    }
    return answer;
}


bool cmp(const string& a, const string& b) {
    if (a + b > b + a)
        return true;
    else
        return false;
}
string programmers::가장큰수(vector<int> numbers)
{
    string answer = "";
    vector<string> strArr;

    for (int i = 0; i < numbers.size(); i++)
    {
        strArr.push_back(to_string(numbers.at(i)));
    }

    sort(strArr.begin(), strArr.end(), cmp);

    for (string str : strArr)
    {
        answer += str;
    }

    if (answer[0] == '0')
        return "0";

    return answer;
}

int programmers::h_index(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            answer = i + 1;
        }
    }

    return answer;
}

int programmers::최소직사각형(vector<vector<int>> sizes)
{
    int answer = 0;
    // 작은 것 가로
    int width = 0;
    // 큰 것 세로
    int height = 0;

    for (auto it : sizes)
    {
        int imax = max(it[0], it[1]);
        int imin = min(it[0], it[1]);
        if (height < imax)
        {
            height = imax;
        }
        if (width < imin)
        {
            width = imin;
        }
    }
    answer = width * height;
    return answer;
}

vector<int> programmers::모의고사(vector<int> answers)
{
    vector<int> answer;
    vector<int> p1 = { 1, 2, 3, 4, 5 };
    vector<int> p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        int answer = answers[i];
        int p1_answer = p1[i % 5];
        int p2_answer = p2[i % 8];
        int p3_answer = p3[i % 10];

        if (answer == p1_answer)
        {
            count1++;
        }
        if (answer == p2_answer)
        {
            count2++;
        }
        if (answer == p3_answer)
        {
            count3++;
        }
    }
    int maxCnt = max(count1, count2);
    maxCnt = max(maxCnt, count3);

    if (maxCnt == count1) answer.push_back(1);
    if (maxCnt == count2) answer.push_back(2);
    if (maxCnt == count3) answer.push_back(3);

    return answer;
}

vector<int> programmers::카펫(int brown, int yellow)
{
    vector<int> answer;

    // yellow를 약수로 나누어 노란색 카펫의 가로와 세로 길이를 찾음
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            int yellow_width = yellow / i;
            int yellow_height = i;

            // 노란색 카펫을 감싸는 전체 카펫의 가로와 세로 길이 계산
            int brown_width = yellow_width + 2;
            int brown_height = yellow_height + 2;

            // 갈색 격자의 수가 주어진 brown과 일치하는지 확인
            if ((brown_width * 2 + brown_height * 2 - 4) == brown) {
                answer.push_back(brown_width);
                answer.push_back(brown_height);
                break;
            }
        }
    }

    return answer;
}


bool 피로도ch[9] = { false };
vector<vector<int>> 피로도dungeon;
int 피로도answer = -1;
void 피로도dfs(int k, int count)
{
    if (k < 0) {
        return;
    }
    for (int i = 0; i < 피로도dungeon.size(); i++)
    {
        //방문하지 않았고 최소 필요 피로도 조건 만족하는 노드로 이동하여 탐색
        if (!피로도ch[i] && k >= 피로도dungeon[i][0])
        { 
            피로도ch[i] = true;
            피로도dfs(k - 피로도dungeon[i][1], count + 1);
            피로도ch[i] = false;
        }
    }
    피로도answer = max(피로도answer, count);
}
int programmers::피로도(int k, vector<vector<int>> dungeons)
{
    피로도dungeon = dungeons;
    피로도dfs(k, 0);

    return 피로도answer;
}

int counter = 0;
bool visit[101];

void dfs(vector<vector<int>>& v, int num) {

    counter++;
    visit[num] = true;

    for (int i = 0; i < v[num].size(); i++) 
    {
        if (!visit[v[num][i]]) 
        {
            dfs(v, v[num][i]);
        }
    }

}
int programmers::전력망둘로나누기(int n, vector<vector<int>> wires)
{
    int answer = n;

    for (int i = 0; i < n - 1; i++) 
    {
        vector<vector<int>> v(n + 1, vector<int>());
        memset(visit, 0, sizeof(visit));
        counter = 0;

        for (int j = 0; j < n - 1; j++) 
        {
            if (i == j)
                continue;
            else 
            {
                // 양방향 연결
                v[wires[j][0]].push_back(wires[j][1]);
                v[wires[j][1]].push_back(wires[j][0]);
            }

        }
        dfs(v, 1);
        if (abs(counter - abs(n - counter)) <= answer)
            answer = abs(counter - abs(n - counter));

    }
    return answer;
}
