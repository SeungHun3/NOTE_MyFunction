#pragma once
#include <iostream>
#include <vector>

using namespace std;

class programmers
{
public:
	// �ؽù���
	int ���ϸ�(vector<int>nums);

	string �����������Ѽ���(vector<string> participant, vector<string> completion);

	bool ��ȭ��ȣ���(vector<string> phone_book);

	int �ǻ�(vector<vector<string>> clothes);
	int �ǻ�_�ٸ����Ǯ��(vector<vector<string>> clothes);

    // ����, ť
	vector<int> �������ڴ½Ⱦ�(vector<int> arr);
	vector<int> ��ɰ���(vector<int> progresses, vector<int> speeds);
	int ���μ���(vector<int> priorities, int location);
	int �ٸ���������Ʈ��(int bridge_length, int weight, vector<int> truck_weights);
	vector<int> �ֽİ���(vector<int> prices);

	// ��
	int ���ʰ�(vector<int> scoville, int K);
	vector<int> ���߿켱����ť(vector<string> operations);
};

