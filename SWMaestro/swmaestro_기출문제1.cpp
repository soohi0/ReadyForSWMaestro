#include <iostream>
#include <vector>

using namespace std;
int N;
int * orange;
int main()
{
	cin >> N;
	orange = new int[N];
	vector<int> v;
	int yangsoo = 0;
	bool wasyangsoo = false;
	int rank;

	for (int i = 0; i < N; i++)
	{
		cin >> rank;
		orange[i] = rank;
		if (rank < 0)
		{
			if (wasyangsoo)
			{
				v.push_back(yangsoo);
			}
			v.push_back(rank);
			yangsoo = 0;
			wasyangsoo = false;
		}
		else
		{
			yangsoo += rank;
			if (i == N - 1)
			{
				v.push_back(yangsoo);
			}
			wasyangsoo = true;
		}
	}
	int leMidRi = -2; // le -1, mid : 0, right L 1
	
	//그 다음의 양수를 찾는다.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	//한바퀴돌며 탐색하여 최대값과 그 값의 idx를 탐색
	//해당 idx의 값을 저장하여 그 값에 접근
	// 만약 그 값이 음수라면 return 그 음수
	//양수라면 왼쪽/ 오른쪽 번갈아가면서 더할것
	//왼쪽에서 양수면 더하고 음수면 일단 배열에 더한 값 저장
	//오른쪽에서
	/*
	7
	-7 7 1 -6 4 9 8
	*/

}