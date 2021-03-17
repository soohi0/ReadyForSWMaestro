#include <iostream>
#include <string>
#include <vector>
#define Max 10001
using namespace std;

int main()
{
	int selfNum[Max] = { 0, };
	for (int i = 1; i < Max; i++)
	{
		string s;
		s = to_string(i);
		int self = i;
		for (int j = 0; j < s.length(); j++)
		{
			string str(1, s[j]);
			self += stoi(str);
		}
		if (self != i && self < Max)
		{
			selfNum[self] += 1;
		}
	
	}
	for (int i = 1; i < Max; i++)
	{
		if (selfNum[i] == 0)
		{
			cout << i << endl;
		}
	}

}