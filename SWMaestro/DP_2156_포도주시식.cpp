//https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>
using namespace std;
int Max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c) return a;
		else return c;
	}
	else
	{
		if (b > c) return b;
		else return c;
	}
}

int main()
{
	int N;
	cin >> N;
	int * arr = new int[N + 1];

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr[i + 1] = num;;
	}
	int * dp = new int[N + 1];
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i < N + 1; i++)
	{
		dp[i] = Max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]);
	}
	//https://mygumi.tistory.com/98
	cout << dp[N];

}