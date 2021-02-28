#include <iostream>
#include <string>
using namespace std;
int main() {

	string s;

	cin >> s;
	int bombcnt = 0;
	int laycnt = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			bombcnt++;
		}
		else if (s[i] == ')')
		{
			laycnt++;
		}
	}
	if (bombcnt == laycnt)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}