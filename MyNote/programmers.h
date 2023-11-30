#pragma once
#include <iostream>
#include <vector>

using namespace std;

class programmers
{
public:
	// 해시문제
	int 폰켓몬(vector<int>nums);

	string 완주하지못한선수(vector<string> participant, vector<string> completion);

	bool 전화번호목록(vector<string> phone_book);

	int 의상(vector<vector<string>> clothes);
	int 의상_다른사람풀이(vector<vector<string>> clothes);

    // 스택, 큐
	vector<int> 같은숫자는싫어(vector<int> arr);
	vector<int> 기능개발(vector<int> progresses, vector<int> speeds);
	int 프로세스(vector<int> priorities, int location);
	int 다리를지나는트럭(int bridge_length, int weight, vector<int> truck_weights);
	vector<int> 주식가격(vector<int> prices);

	// 힙
	int 더맵게(vector<int> scoville, int K);
	vector<int> 이중우선순위큐(vector<string> operations);
};

