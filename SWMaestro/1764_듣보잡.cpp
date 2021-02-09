/////////////�ð��ʰ�(TLE)�߻� =>����Ž��(binary Search)�� �̿��ؾ��Ѵ� -> ���������� ���� �ʿ�!
//string �� compare�Լ��� ���������� �񱳸� ���ش�.

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//���ĺ��� 26��
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

	if (v[curidx] < s) //s�� �ڿ� /��ǥ������ ����
	{
		return Binary_Search( s, curidx+1, end);
	}
	else if (v[curidx] > s) // s�� �տ�/��ǥ������ ����
	{
		return Binary_Search(s, front, curidx-1);
	}
	else if(!v[curidx].compare(s))
	{//������
		return s;
	}

	//string ss;
	//if (v[curidx].compare(s) == -1) //��ǥ���� ������ �̰ŋ����� ��� Ʋ�� �ù�
	//{
	//	ss = Binary_Search(s, curidx + 1, end);
	//}
	//else if (v[curidx].compare(s) == 1) //��ǥ���� ������ �̰ŋ����� ��� Ʋ�� �ù�
	//{
	//	ss =  Binary_Search(s, front, curidx - 1);
	//}
	//else if (!v[curidx].compare(s))
	//{//������
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