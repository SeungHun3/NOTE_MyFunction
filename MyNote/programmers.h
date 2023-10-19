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
};

