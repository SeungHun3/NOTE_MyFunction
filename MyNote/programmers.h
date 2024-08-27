#pragma once
#include <iostream>
#include <vector>

using namespace std;

class programmers
{
public:
	// 해시문제
	static int 폰켓몬(vector<int>nums);
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

	// 정렬
	vector<int> k번째수(vector<int> array, vector<vector<int>> commands);
	string 가장큰수(vector<int> numbers);
	int h_index(vector<int> citations);

	// 탐색
	int 최소직사각형(vector<vector<int>> sizes);
	vector<int> 모의고사(vector<int> answers);
	vector<int> 카펫(int brown, int yellow);
	static int 피로도(int k, vector<vector<int>> dungeons); 
	static int 전력망둘로나누기(int n, vector<vector<int>> wires);
	static int 모음사전(string word);
	static int 타겟넘버(vector<int> numbers, int target);
	static int 네트워크(int n, vector<vector<int>> computers);
	
	static int 가장많이받은선물(vector<string> friends, vector<string> gifts);

};

