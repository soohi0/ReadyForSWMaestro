#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	cin >> N;

	bool * cango = new bool[N];
	int * dp = new int[N];
	string num;
	cin >> num;

	for (int i = 0; i < N; i++)
	{
		cango[i] = num[i]-'0';
		cout << cango[i] << endl;
	}
	dp[0] = 1;
	if (cango[1] == 0)
	{
		dp[1] = dp[0];
	}
	else
	{
		dp[1] = 1;
	}
	for (int i = 2; i < N; i++)
	{
		if (cango[i] == 0)
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			if (cango[i - 1] == 1 && cango[i - 2] == 1)
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else if (cango[i - 1] == 1 && cango[i - 2] == 0)
			{
				dp[i] = dp[i - 2];
			}
			else if (cango[i - 1] == 0 && cango[i - 2] == 1)
			{
				dp[i] = dp[i - 1];
			}
		}
	}
	cout << dp[N - 1];
	return 0;
}