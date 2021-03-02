//https://www.acmicpc.net/problem/20413
#include <iostream>
#include <map>
#include <string>

using namespace std;
int N;
int ranks[5] = {0, };
//int score[36] = { 0, };
int main()
{
	map <char, int> m;
	cin >> N;
	for (int i = 1; i < 5; i++)
	{
		cin >> ranks[i];
	}
	m.insert(make_pair('B', 0));
	m.insert(make_pair('S', 1));
	m.insert(make_pair('G', 2));
	m.insert(make_pair('P', 3));
	m.insert(make_pair('D', 4));

	string rankstr;
	cin >> rankstr;
	int preScore = 0;
	int curScore = 0;

	for (int i = 0; i < N; i++)
	{
		if (rankstr[i] != 'D')
		{
			curScore += (ranks[m[rankstr[i]]+1]-1 - preScore);
			preScore = ranks[m[rankstr[i]]+1] - 1 - preScore;
		}
		else
		{
			curScore += ranks[m[rankstr[i]]];
			preScore = ranks[m[rankstr[i]]];
		}
	}
	cout << curScore;

	//BSG
	//1, B : 0 ~ 29 29
	//2. S : 30 ~ 59 30
	//3. G : 60 ~ 89 59
	//4. p : 90 ~ 149 99
	//5. d : 150~      

	// 29 + 30 + 59 : 59 + 59


}