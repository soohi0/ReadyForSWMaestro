#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int N;
priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;
/*
vector<int> MaxSpanningTree(vector<vector<int> > node)
{
	int size = pq.size();
	int * subNode = new int[N];
	vector<int> choosedV;
	for (int i = 0; i < N; i++)
	{
		subNode[i] = i;
	}
	for (int i = 0; i < size; i++)
	{
		pair< int, pair<int, int>> pp;
		pair<int, int> p;
		pp = pq.top();
		p = pp.second;
		int w = pp.first;
		int MaxX = p.first;
		int MaxY = p.second;
		for (int i = 0; i < N; i++)
		{
			cout << "sub : " << subNode[i] << endl;
		}
		if (subNode[MaxX] != subNode[MaxY])
		{
			
			choosedV.push_back(w);
			if (subNode[MaxX] > subNode[MaxY])
			{
				subNode[MaxY] = subNode[MaxX];
			}
			else
			{
				subNode[MaxX] = subNode[MaxY];
			}

		}

		cout << "w :" << pp.first << " x:" << p.first << " y:" << p.second << endl;
		pq.pop();

	}

	return choosedV;

}*/
bool isAllVisited(vector<vector<int> > &node, int lastNode)
{
	for (int i = 0; i < N; i++)
	{
		if (node[i][lastNode] != -1 && node[i][lastNode] != 0)
		{
			return false;
		}
	}
	return true;
}
void DFS(vector<vector<int> > &node)
{
	stack<int> stk;
	vector<int> weightSums;
	vector<int> sums(N);
	//sums = { 0, };
	pair< int, pair<int, int>> pp = pq.top();
	pair<int, int> p = pp.second;
	stk.push(p.first);
	stk.push(p.second);
	//int wsum = node[p.second][p.first];
	int lastNode = p.second;
	int preNode = p.first;
	while (!stk.empty())
	{
		lastNode = stk.top();
		cout << "node" << node[lastNode][preNode] << lastNode << endl;
		if (sums[lastNode] < (sums[lastNode] + node[lastNode][preNode]))
		{
			sums[lastNode] += node[lastNode][preNode];
		}
		cout << "sum : " << sums[lastNode] << endl;
		node[lastNode][preNode] = -1;
		if (!isAllVisited(node, lastNode))
		{
			for (int i = 0; i < N; i++)
			{
				if (node[i][lastNode] != -1 && node[i][lastNode] != 0)
				{
					stk.push(i);
					preNode = lastNode;
				}
			}
		}
		else {
			weightSums.push_back(sums[lastNode]);
			preNode = lastNode;
			stk.pop();

		}

	}
	for (int i = 0; i < weightSums.size(); i++)
	{
		cout << "result : "<<weightSums[i] << " ";
	}


}
void inputPQ(vector<vector<int> > node)
{
	for (int i = 0; i < N ; i++)
	{
		for (int j = i; j < N; j++)
		{
			//cout << node[i][j] << " ";
			if (node[i][j] != 0)
			{
				pair< int, pair<int, int>> pp;
				pair<int, int> p = make_pair(j, i);
				pp = make_pair(node[i][j], p);
				pq.push(pp);
			}
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
				
			}
		}
	}
	inputPQ(node);
	DFS(node);
	//vector<int> result;
	//int answer = 0;
	//result = MaxSpanningTree(node);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	answer += result[i];
	//}
	//cout << "Á¤´ä : "<<answer << endl;
}
