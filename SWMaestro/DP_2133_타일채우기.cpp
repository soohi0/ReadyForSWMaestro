//https://www.acmicpc.net/problem/2133
#include <iostream>

using namespace std;

int main()
{
//�׸��׷����鼭 ��Ģ�� ã�Ҵ�.
	int N;
	int tile[15] = { 0 };
	cin >> N;
	if (N % 2 == 1) cout << 0;
	else
	{
		tile[0] = 3;
		tile[1] = 3 * 3 + 2;
		for (int i = 2; i < (N / 2); i++)
		{
			//cout << "i : " << i << endl;
			tile[i] = tile[i - 1] * 3;
			for (int j = 0; j < i - 1; j++)
			{
				tile[i] += 2 * tile[j];
				//cout << "tile[j] : " << tile[j] << endl;
			}
			if (N > 3) tile[i] += 2;
		}
		
		cout << tile[N / 2-1];

	}

}