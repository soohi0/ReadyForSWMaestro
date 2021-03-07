//https://www.acmicpc.net/problem/20413
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, K;
void BFS(vector< vector <int> > &dp, int *time, int target)
{
	queue<int> q;
	priority_queue<int, vector<int>, greater<int>> pq; //sum ½Ã°£
	q.push(1);
	/*while (!q.empty()) {
		int num = q.front();

		for (int i = 0; i < dp[num].size(); i++)
		{
			q.push(dp[num][i]);
		}
	}*/
	int num = 1;
	int sum = 0;
	sum += time[num - 1];

	while (num != target)
	{
		for (int i = 0; i < dp[num - 1].size(); i++)
		{

		}
	}

}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;
		int * time = new int[N];
		vector< vector <int> > dp (N);
		//int * sumtime = new int [N];
		for (int j = 0; j < N; j++)
		{
			cin >> time[i];
			vector<int> v;
			dp.push_back(v);
		}
		for (int j = 0; j < K; j++)
		{
			
			int num1, num2;
			cin >> num1 >> num2;
			dp[num1].push_back(num2);
		}
		int target;
		cin >> target;
		BFS(dp, time, target);


	}
}