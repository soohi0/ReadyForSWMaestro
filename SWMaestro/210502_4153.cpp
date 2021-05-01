#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	vector<string> v;
	vector<int> vint(3);
	do
	{
		cin >> a >> b >> c;
		vint[0] = a;
		vint[1] = b;
		vint[2] = c;

		sort(vint.begin(), vint.end());

		if (pow(vint[2], 2) == pow(vint[0], 2) + pow(vint[1], 2)) {
			if (!(a == 0 && b == 0 && c == 0))
			{
				v.push_back("right");
			}
		}
		else
		{
				v.push_back("wrong");
			
		}
	} while (!(a == 0 && b == 0 && c == 0));

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}