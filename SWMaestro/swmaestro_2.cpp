#include <iostream>

using namespace std;
int N;
int * balpan;
bool * already; //이미 밟은거면
int main()
{
	cin >> N;
	balpan = new int[N];
	already = new bool[N];

	for (int i = 0; i < 10; i++)
	{
		int input;
		cin >> input;
		balpan[i] = input;
	}
	for (int idx = 0; idx < 3; idx++)
	{
		int count = 1;
		while (already[idx] != 1)
		{
			already[idx] = 1;
			idx += balpan[idx];
			count++;
		}
		cout << count;
	}

}