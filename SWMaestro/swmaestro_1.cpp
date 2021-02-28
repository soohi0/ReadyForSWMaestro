#include <iostream>
#include <vector>
#include <algorithm>

//#5
using namespace std;
int N;
vector<int> t(100000000);
int main()
{
	cin >> N;
	vector<int> score(N*N);
	int maxT = 0;
	for (int i = 0; i < N*N; i++)
	{
		int cycle;
		cin >> score[i] >> cycle;
		for (int j = 0; j < cycle; j++)
		{
			int inputT;
			cin >> inputT;
			maxT = max(maxT, inputT);
			t[inputT-1] = max(t[inputT-1], score[i]);
		}
	}
	int maxScore = 0;
	for (int i = 0; i < maxT; i++)
	{
		maxScore += t[i];
	}
	cout << maxScore << endl;
}