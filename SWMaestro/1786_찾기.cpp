#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string T;
string P;
int sameCnt = 0;
int  findP(int j)
{
	//���߿� ��ġ��
	for (int i = 0; i < P.length(); i++)
	{
		if (T[i + j] != P[i])
		{
			j = i;

			cout << "j : " << j << endl;
			string str = "";
			str.push_back(P[0]); //string �� push back �� �ֱ���
			int lenCnt = 0;
			int maxCnt = 0;       //j �� �´� �ִ� ��ġ�� ����
			int startIdx = 0;     //j �� �´� �ִ� ��ġ�� str�� ù��° idx
			string matchstr = ""; //j �� �´� �ִ� ��ġ�� str
			bool wasSame = false;

			for (int k = 1; k < j; k++)
			{
				//if (P[j] == P[j - k+1])
				//cout << "P[k]:" << P[k] << endl;
				//cout << "str[0 + lenCnt]" << str[0 + lenCnt] << "'"<<  endl;

				if (P[k] != str[0 + lenCnt])
				{
					wasSame = false;
				}
				else
				{
					while (P[k] == str[0 + lenCnt])
					{
						//cout << "k : " << k << endl;
						if (!wasSame)
						{
							//�ʱ�ȭ
							lenCnt = 0;
							startIdx = k;
						}
						wasSame = true;
						lenCnt++;
						if (maxCnt < lenCnt)
						{
							maxCnt = lenCnt;
							matchstr += P[k];
							startIdx = k - lenCnt;
						}
						str += P[lenCnt];
						//cout << "matchstr : " << matchstr << endl;
						//cout << "str : " << str << endl;
						//cout << "lencnt : " << lenCnt << endl;

					}
				}

			}
			cout << "matchstr : " << matchstr << endl;
			return j + i;
		}
		else
		{
			if (i == P.length() - 1)
			{
				sameCnt++;
				cout << "sameidx" << j + i;
				return j + i;
			}
		}
	}
	return j;
}
//�ش� �ε����� �ش��ϴ� ����ŭ�� ������ ���ڿ��� �ݺ��ǳ�?
//�ݺ��Ǹ� ���ڿ��� ���̸�ŭ �Է�, �ȵǸ� 0
int * fail;
void failP()
{
	//int j = 0; // �� ���̻� ���� ���� idx
	for (int i = 1, j = 0; i < P.length(); i++)
	{
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}
}
int main()
{
	string input = "";
	char inputs;
	getline(cin, T); //getline �� cin�� �ٸ��� ���鹮�ڸ� �д´�. �׸��� ���๮�ڸ� �޾��� �� �б⸦ ����ġ�� �ȴ�.
	cout << "'" << T[3] << "'" << endl;
	cin  >> P;
	fail = new int [P.length()];
	fail = { 0, };
	//abcdabc
	//findP();
	failP();
	for (int i = 0; i < P.length(); i++)
	{
		cout << "fail : " << fail[i] << endl;
	}
}
/*
ABCDABCDABDE
ABCDABE
*/