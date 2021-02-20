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
	//나중에 고치기
	for (int i = 0; i < P.length(); i++)
	{
		if (T[i + j] != P[i])
		{
			j = i;

			cout << "j : " << j << endl;
			string str = "";
			str.push_back(P[0]); //string 도 push back 이 있구나
			int lenCnt = 0;
			int maxCnt = 0;       //j 에 맞는 최대 겹치는 길이
			int startIdx = 0;     //j 에 맞는 최대 겹치는 str의 첫번째 idx
			string matchstr = ""; //j 에 맞는 최대 겹치는 str
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
							//초기화
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
//해당 인덱스에 해당하는 수만큼의 길이의 문자열이 반복되나?
//반복되면 문자열의 길이만큼 입력, 안되면 0
int * fail;
void failP()
{
	//int j = 0; // 비교 접미사 길이 시작 idx
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
	getline(cin, T); //getline 은 cin과 다르게 공백문자를 읽는다. 그리고 개행문자를 받았을 때 읽기를 끝마치게 된다.
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