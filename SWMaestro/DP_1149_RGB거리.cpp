//https://www.acmicpc.net/problem/1149
#include <iostream>

using namespace std;
int N;
int Min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	cin >> N;
	int cost[1001][3];
	int DP[1001][3];


	for (int i = 0; i < N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	DP[0][0] = cost[0][0];
	DP[0][1] = cost[0][1];
	DP[0][2] = cost[0][2];

	for (int i = 1; i < N; i++)
	{
		DP[i][0] = Min(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
		DP[i][1] = Min(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
		DP[i][2] = Min(DP[i - 1][1], DP[i - 1][0]) + cost[i][2];
	}
	cout << Min(Min(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << cost[i][j] << " ";
	//	}
	//	cout << endl;
	//}

}