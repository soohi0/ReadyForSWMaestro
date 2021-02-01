#include <iostream>

using namespace std;


int n;
int min(int a, int b)
{
	if (a > b) return b;
	else return a;
}
int main()
{
	cin >> n;

	int * mem = new int [n+1];
	mem[0] = 0;
	mem[1] = 0;
	mem[2] = 1;
	mem[3] = 1;

	for (int i = 4; i < n+1; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 2 == 0)
			{
				mem[i] = min(min(mem[i / 3], mem[i / 2]), mem[i - 1]) + 1;
			}
			else
			{
				mem[i] = min(mem[i / 3], mem[i - 1]) + 1;
			}
			
		}
		else if (i % 2 == 0)
		{
			mem[i] = min(mem[i / 2], mem[i - 1]) + 1;
		}
		else
		{
			mem[i] = mem[i - 1] + 1;
		}
	}
	cout << mem[n];

	//cout << n;

}