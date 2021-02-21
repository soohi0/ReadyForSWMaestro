#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N;
priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;

void MaxSpanningTree(vector<vector<int> > node)
{
	int size = pq.size();
	for (int i = 0; i < size; i++)
	{
		pair< int, pair<int, int>> pp;
		pair<int, int> p;
		pp = pq.top();
		p = pp.second;
		//cout << "w :" << pp.first << " x:" << p.first << " y:" << p.second << endl;
		pq.pop();
		pq.pop();

	}



}
void PrintVec(vector<vector<int> > node)
{
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << node[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	cin >> N;
	vector<vector<int> > node(N);
	
	for (int i = 0; i < N; i++)
	{
		vector<int> v(N);
		node[i] = v;
		int nodeNum;
		int inputNum = 0;

		cin >> nodeNum >> inputNum;
		cout << endl;
		while (inputNum != -1)
		{
			int inputWeight;
			int inputPreNum = inputNum;
			cin >> inputWeight >> inputNum;
			if (inputPreNum != -1)
			{
				node[nodeNum-1][inputPreNum -1] = inputWeight;
				pair< int, pair<int, int>> pp;
				pair<int, int> p = make_pair(inputPreNum - 1, nodeNum - 1);
				pp = make_pair(inputWeight, p);
				pq.push(pp);
			}
		}
	}
	PrintVec(node);
	MaxSpanningTree(node);
}
