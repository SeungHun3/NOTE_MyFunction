#pragma once
#include <iostream>
#include <vector>

using namespace std;

class programmers
{
public:
	// �ؽù���
	static int ���ϸ�(vector<int>nums);
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

	// ����
	vector<int> k��°��(vector<int> array, vector<vector<int>> commands);
	string ����ū��(vector<int> numbers);
	int h_index(vector<int> citations);

	//���� Ž��
	int �ּ����簢��(vector<vector<int>> sizes);
	vector<int> ���ǰ��(vector<int> answers);
	vector<int> ī��(int brown, int yellow);
	static int �Ƿε�(int k, vector<vector<int>> dungeons); 
	static int ���¸��ѷγ�����(int n, vector<vector<int>> wires);

};

