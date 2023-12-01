#include "programmers.h"
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <queue>

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
        answer = (int)count;
    }
    else 
    {
        answer = (int)uniqueNums.size();
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
            for (size_t i = min; i <= phone.size(); ++i)
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

vector<int> programmers::�������ڴ½Ⱦ�(vector<int> arr)
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

vector<int> programmers::��ɰ���(vector<int> progresses, vector<int> speeds)
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

int programmers::���μ���(vector<int> priorities, int location)
{
    int answer = 0;

    vector<int> sortarr = priorities;
    sort(sortarr.begin(), sortarr.end());
    list<int>dec;
    for (auto it : sortarr)
    {
        dec.push_front(it);
    }
    // Ÿ�� iterator ���ϱ�
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

int programmers::�ٸ���������Ʈ��(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;// �ð�
    int bridge = bridge_length;
    int bweight = weight;
    list<int> wait_trucks;
    list<int>going_trucks; // value = ����,length = ���� �ǳʰ� �ִ� �ð�

    for (auto it : truck_weights)
    {
        wait_trucks.push_back(it);
    }

    while (true)
    {

        answer++;

        // Ʈ������
        if (bridge <= going_trucks.size())
        {
            going_trucks.pop_front();
        }

        int going_weight = 0;
        for (auto it : going_trucks)
        {
            going_weight += it;   // ���� ���ؼ�
        }


        // Ʈ�� �ֱ� = ���Ʈ�� ���� �ǳʴ� Ʈ���� �ֱ�
        if (!wait_trucks.empty()) // ��ٸ��� Ʈ���� �ִٸ�
        {

            int start_Truck = wait_trucks.front();

            if (bweight >= start_Truck + going_weight) // Ʈ���� �� �� ���� ��
            {
                going_weight += start_Truck;
                going_trucks.push_back(start_Truck);
                wait_trucks.pop_front();

            }
            else // Ʈ���� �� �� ���� ��
            {
                going_trucks.push_back(0);
            }


        }
        else // ��ٸ��� Ʈ���� ���ٸ�
        {
            // �ǳʰ� �ִ� Ʈ���� ���ٸ�
            if (going_weight == 0)
            {
                break;
            }
            going_trucks.push_back(0);
        }

    }

    return answer;
}

vector<int> programmers::�ֽİ���(vector<int> prices)
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

int programmers::���ʰ�(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > scv(scoville.begin(), scoville.end());

    while (true)
    {
        // ��� ������ ���ں����� k �̻� ���� �� ������
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

vector<int> programmers::���߿켱����ť(vector<string> operations)
{
    vector<int> answer;
    list<int> queue;
    while (!operations.empty())
    {
        string str = operations[0];
        operations.erase(operations.begin());
        // ����
        if (str[0] == 'I')
        {
            string substr = str.substr(2, str.size() - 2);
            int push = stoi(substr);
            queue.push_back(push);
        }

        //����
        else if (str[0] == 'D')
        {
            if (queue.empty())
                continue;

            string substr = str.substr(2, str.size() - 2);
            int push = stoi(substr);
            if (push > 0)
            {
                //�ִ밪 ����
                list<int>::iterator MaxIter = max_element(queue.begin(), queue.end());
                queue.erase(MaxIter);
            }
            else
            {
                // �ּҰ� ����
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

vector<int> programmers::k��°��(vector<int> array, vector<vector<int>> commands)
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
string programmers::����ū��(vector<int> numbers)
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

int programmers::�ּ����簢��(vector<vector<int>> sizes)
{
    int answer = 0;
    // ���� �� ����
    int width = 0;
    // ū �� ����
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

vector<int> programmers::���ǰ��(vector<int> answers)
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

vector<int> programmers::ī��(int brown, int yellow)
{
    vector<int> answer;

    // yellow�� ����� ������ ����� ī���� ���ο� ���� ���̸� ã��
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            int yellow_width = yellow / i;
            int yellow_height = i;

            // ����� ī���� ���δ� ��ü ī���� ���ο� ���� ���� ���
            int brown_width = yellow_width + 2;
            int brown_height = yellow_height + 2;

            // ���� ������ ���� �־��� brown�� ��ġ�ϴ��� Ȯ��
            if ((brown_width * 2 + brown_height * 2 - 4) == brown) {
                answer.push_back(brown_width);
                answer.push_back(brown_height);
                break;
            }
        }
    }

    return answer;
}


bool �Ƿε�ch[9] = { false };
vector<vector<int>> �Ƿε�dungeon;
int �Ƿε�answer = -1;
void �Ƿε�dfs(int k, int count)
{
    if (k < 0) {
        return;
    }
    for (int i = 0; i < �Ƿε�dungeon.size(); i++)
    {
        //�湮���� �ʾҰ� �ּ� �ʿ� �Ƿε� ���� �����ϴ� ���� �̵��Ͽ� Ž��
        if (!�Ƿε�ch[i] && k >= �Ƿε�dungeon[i][0])
        { 
            �Ƿε�ch[i] = true;
            �Ƿε�dfs(k - �Ƿε�dungeon[i][1], count + 1);
            �Ƿε�ch[i] = false;
        }
    }
    �Ƿε�answer = max(�Ƿε�answer, count);
}
int programmers::�Ƿε�(int k, vector<vector<int>> dungeons)
{
    �Ƿε�dungeon = dungeons;
    �Ƿε�dfs(k, 0);

    return �Ƿε�answer;
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
int programmers::���¸��ѷγ�����(int n, vector<vector<int>> wires)
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
                // ����� ����
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
