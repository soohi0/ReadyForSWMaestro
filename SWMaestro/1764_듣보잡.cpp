/////////////시간초과(TLE)발생 =>이진탐색(binary Search)를 이용해야한다 -> 사전순으로 정렬 필요!
//string 의 compare함수는 사전순으로 비교를 해준다.

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//알파벳은 26개
vector<string> v;

priority_queue < string, vector<string>, greater<string> > pq;

string Binary_Search( string s, int front, int end)
{
	//for (int i = 0; i < pq.size(); i++)
	//{
	//	string str = pq[i];
	//	if (cmpStr(str, s))
	//	{
	//		return str;
	//	}
	//}
	//return "";
	if (front > end) return "";
	int curidx = (int)(front + end) / 2;

	if (v[curidx] < s) //s가 뒤에 /이표현으로 쓰셈
	{
		return Binary_Search( s, curidx+1, end);
	}
	else if (v[curidx] > s) // s가 앞에/이표현으로 쓰셈
	{
		return Binary_Search(s, front, curidx-1);
	}
	else if(!v[curidx].compare(s))
	{//같으면
		return s;
	}

	//string ss;
	//if (v[curidx].compare(s) == -1) //이표현은 쓰지마 이거떄문에 계속 틀림 시발
	//{
	//	ss = Binary_Search(s, curidx + 1, end);
	//}
	//else if (v[curidx].compare(s) == 1) //이표현은 쓰지마 이거떄문에 계속 틀림 시발
	//{
	//	ss =  Binary_Search(s, front, curidx - 1);
	//}
	//else if (!v[curidx].compare(s))
	//{//같으면
	//	return s;
	//}
	//return ss;


}


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		string newstr = Binary_Search(s, 0, v.size()-1);
		if (newstr != "") pq.push(newstr);

	}
	int pqsize = pq.size();
	cout << pqsize << endl;
	for (int i = 0; i < pqsize; i++)
	{
		cout <<pq.top()<< endl;
		pq.pop();
	}


	return 0;
}