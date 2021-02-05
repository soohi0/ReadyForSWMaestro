#include <iostream>

using namespace std;

int n;
int zero = 0;
int one = 0;
bool ** cPaper;
void PrintMap()
{
	cout << "=======================" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cPaper[i][j] << " ";
		}
		cout << endl;
	}
}
bool CheckInRange(int x, int y)
{
	if (x < n && y < n && x >= 0 && y >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Check1or0orNot(int n, int x, int y)
{
	if (n < 1) return -2; //크기가 0

	int oneOrzero = -1;
	oneOrzero = cPaper[y][x];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (CheckInRange(j + x, i + y) )
			{
				if (oneOrzero != cPaper[i + y][j + x])
				{
					return -1; // 틀린게 있는것.
				}
				else
				{
					oneOrzero = cPaper[i + y][j + x];
				}
			}
		}
	}
	if (oneOrzero != -1)
	{
		return oneOrzero; //모두 같은게 1이면 1반환, 모두 같은게 0이면 0반환
	}
}
void CutMap(int n, int x, int y)
{
	int result = Check1or0orNot(n, x, y);
	if (result == -1)
	{
		CutMap(n / 2, x, y);
		CutMap(n / 2, x + n/2, y);
		CutMap(n / 2, x , y + n/2);
		CutMap(n / 2, x + n/2, y + n / 2);
	}
	else
	{
		if (result == 0)
		{
			zero++;
		}
		else
		{
			one++;
		}
	}
}

int main()
{
	cin >> n;
	cPaper = new bool *[n];
	for (int i = 0; i < n; i++)
	{
		cPaper[i] = new bool[n];
		for (int j = 0; j < n; j++)
		{
			bool onezero;
			cin >> onezero;
			cPaper[i][j] = onezero;
		}
	}
	//PrintMap();
	CutMap(n, 0, 0);
	cout << zero << endl;
	cout << one << endl;

}