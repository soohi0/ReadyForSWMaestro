#include <iostream>
#include <vector>

using namespace std;
int T, W;

int main()
{
	cin >> T >> W;
	int * tree = new int[T];
	vector<int> dp(T);
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		tree[i] = num;
	}
	for (int i = 0; i < T-1; i++)
	{
		
	}
}