#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue< pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p;
		cin >> p.first;
		p.second = i;
		pq.push(p);
		arr[i] = -1;
	}
	int cnt = 0;
	int preNum = -1;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p = pq.top();
		//cout <<"first : "<<p.first << " , second" <<p.second <<", pre:" << preNum <<endl;
		if (p.first == preNum)
		{
			cnt--;
			arr[p.second] = cnt;
		}
		else
		{
			arr[p.second] = cnt;
		}

		cnt++;
		pq.pop();
		preNum = p.first;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}