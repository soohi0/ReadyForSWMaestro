#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;
int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int Min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int fast_atoi(string str)
{
	int val = 0;
	for (int i = 0; i < str.length(); i++)
	{
		val = val * 10 + (str[i] - '0');
	}
	return val;
	
}

int main()
{
	int N;
	cin >> N;
	vector<string>Starttime(N);
	vector<string>Endtime(N);

	int max = 0;
	int min = 2359;	

	for (int i = 0; i < N; i++)
	{
		char munza;
		cin >> Starttime[i] >> munza >> Endtime[i];
		char stTime[] = { Starttime[i][0] ,Starttime[i][1] , Starttime[i][3] , Starttime[i][4] };
		int time1 = 1;
		int STime = 0;
		for (int j = 3; j >= 0; j--)
		{
			STime += time1 * (stTime[j] - '0');
			time1 *= 10;
		}
		max = Max(max, STime);
		char EndTime[4] = { Endtime[i][0] ,Endtime[i][1] , Endtime[i][3] , Endtime[i][4] };

		int time2 = 1;
		int ETime = 0;
		for (int j = 3; j >= 0; j--)
		{
			ETime += time2 * (EndTime[j] - '0');
			time2 *= 10;
		}

		min = Min(min, ETime);
	}
	cout << max << endl;
	cout << min << endl;

	if (max > min) cout << "-1";
	else
	{
		//stringstream ss1;
		//ss1 << max;
		//string stStr = ss1.str();

		//stringstream ss2;
		//ss2 << min;
		//string endStr = ss2.str();
		int st1 = (int)max / 100;
		int st2 = max % 100;
		int end1 = (int)min / 100;
		int end2 = min % 100;

		if (st1 < 10)
		{
			cout.width(2);
			cout.fill('0');
			cout << st1;
		}
		else cout << st1;
		cout << ":";
		if (st2 < 10)
		{
			cout.width(2);
			cout.fill('0');
			cout << st2;
		}
		else cout << st2;
		cout << " ~ ";
		if (end1 < 10)
		{
			cout.width(2);
			cout.fill('0');
			cout << end1;
		}
		else cout << end1;
		cout << ":";
		if (end2 < 10)
		{
			cout.width(2);
			cout.fill('0');
			cout << end2;
		}
		else cout << end2;


		//cout << (int)max / 100<< ":" << max % 100 << " ~ " << (int)min / 100 << ":" << min % 100 << endl;
	}


}