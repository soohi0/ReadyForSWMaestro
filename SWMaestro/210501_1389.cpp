#include <iostream>
#define INF 500001
using namespace std;
int n, m;
int kevin[101][101];
int Min(int a, int b) {
	if (a < b) return a;
	else return b;
}
/*
//전형적인 플로이드 알고리즘

void floyd(void)
{

		for (int k = 1; k <= N; k++)

				 for (int i = 1; i <= N; i++)

						 for (int j = 1; j <= N; j++)

								 if (i == j)

										  continue;

								 else if (graph[i][k] && graph[k][j])

								 {

										  if (graph[i][j] == 0)

												  graph[i][j] = graph[i][k] + graph[k][j];

										  //베이컨의 수가 적어야하므로

										  else

												  graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

								 }

}



*/
void DFS(int y, int x, int cnt)
{
	//0, 1
	for (int i = y + 1; i < n; i++)
	{
		if (kevin[y][i] == 1)
		{
			cnt++;
			if (i == x)
			{
				kevin[y][x] = cnt;
			}
			else
			{
				
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int fi, se; //fi - y, se - x
		cin >> fi >> se;
		kevin[fi-1][se-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (kevin[i][j] != 1)
			{
				kevin[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			if (kevin[i][j] != 1)
			{
				DFS(i, j, 0);
			}
		}
	}
	
}