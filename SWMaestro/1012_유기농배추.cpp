//#include <Windows.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int m;//가로
int n;//세로
struct Dir
{
	int x;
	int y;
};
Dir directions[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
void PrintMap( int** farm)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << farm[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}
bool IsinRange(int x, int y)
{
	if (x >= 0 && x < m && y >= 0 && y < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool InputFirstPos(int ** farm, queue< pair<int, int> > &q)
{
	bool first = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (farm[i][j] == 1 && !first)
			{
				q.push(make_pair(j, i));
				farm[i][j] = -1;
				first = true;
			}
		}
	}
	if (q.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}
int BFS(int** farm)
{
	int count = 0;
	queue< pair<int, int> > q;
	//첫 좌표 넣기'
	while (InputFirstPos(farm, q))
	{
		while (!q.empty())
		{
			pair<int, int> curPos = q.front();
			//cout << curPos.first << " : " << curPos.second << endl;
			for (int i = 0; i < 4; i++)
			{
				int newPosX = directions[i].x + curPos.first;
				int newPosY = directions[i].y + curPos.second;
				//cout << newPosX << " : " << newPosY << endl;

				if (IsinRange(newPosX, newPosY))
				{
					if (farm[newPosY][newPosX] == 1)
					{
						q.push(make_pair(newPosX, newPosY));
						farm[newPosY][newPosX] = -1;
						//PrintMap(farm);
						//Sleep(1000);
					}
				}
			}
			q.pop();
		}
		count++;

	}

	
	return count;
	
	//방문한 곳은 -1로,

	//좌표는 4방향

	//queue 사용

}


int main()
{
	int T;
	cin >> T;
	int * result = new int[T];
	for (int i = 0; i < T; i++)
	{
		int k;
		cin >> m >> n >> k;
		int ** farm = new int *[n];
		for (int j = 0; j < n; j++)
		{
			farm[j] = new int[m];
			for (int k = 0; k < m; k++)
			{
				farm[j][k] = 0;
			}
		}
		for (int j = 0; j < k; j++)
		{
			int x;
			int y;
			cin >> x >> y;
			farm[y][x] = 1;
		}
		//PrintMap(m, n, farm);
		//cout << BFS(farm);
		result[i] = BFS(farm);
	}
	for (int i = 0; i < T; i++)
	{
		cout << result[i] << " ";
	}

	
}