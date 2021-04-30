//https://www.acmicpc.net/problem/1107
#include <iostream>
#include <vector>

using namespace std;
int N, M;
bool isthereWrongNum(vector<int> num, vector<int> & wrongNumarr)
{
	for (int j = 0; j < num.size(); j++)
	{
		for (int i = 0; i < wrongNumarr.size(); i++)
		{
			if (num[j] == wrongNumarr[i])
			{
				return true;
			}
		}
	}
	
	return false;
}
vector<int> devideint(int num)
{
	vector<int> devide;
	int basoo = 10;
	int arridx = 0;
	while (num / (basoo / 10) >= 1)
	{
		int numb = (int)num % basoo;
		devide.push_back(numb / (basoo / 10));
		basoo *= 10;
	}
	return devide;
}

int main()
{
	int N, M;
	vector<int> wrongNum;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		wrongNum.push_back(num);
	}
	//받은 숫자를 자리수대로 배열에 넣기(역순)
	
	vector<int> numarr = devideint(N);


	//for (int i = 0; i < numarr.size(); i++)
	//{
	//	cout << numarr[i] << " ";
	//}
	int curNum = 100;
	//숫자 차례대로 일치하면 pass, 일치하지 않으면 전후로 탐색
	int * inputNum = new int[numarr.size()];
	int count = 0;
	if (N == 100)
	{
		count = 0;
		
	}
	else if (M == 10)
	{
		//전체가고장난것
		count = N - curNum;
	}
	else
	{
		int num = N;
		int numsub = N;
		int numplus = N;
		int pluscnt = 0;
		int subcnt = 0;
		vector<int> numsubarr;
		vector<int> numplusarr;

		do {
			if (numsub - 1 < 0)
			{
				numsub = 0;
				numsubarr = { 0 };
			}
			else
			{
				numsub = numsub - 1;
				subcnt++;
				numsubarr = devideint(numsub);
				/*for (int i = 0; i < numsubarr.size(); i++)
				{
					cout <<"-- : "<< numsubarr[i] << " ";
				}
				cout << endl;*/
			}

			if (numplus + 1 > 1000000)
			{
				numplus = 1000000;
				numplusarr = { 0, 0, 0, 0, 0, 0, 1 };
			}
			else
			{
				numplus = numplus + 1;
				pluscnt++;
				numplusarr = devideint(numplus);
				/*for (int i = 0; i < numplusarr.size(); i++)
				{
					cout << "++ : " << numplusarr[i] << " ";
				}
				cout << endl;*/

			}
		} while (isthereWrongNum(numsubarr, wrongNum) && isthereWrongNum(numplusarr, wrongNum));
		if (pluscnt < subcnt)
		{
			count = numplus - N;
			count += numplusarr.size();
		}
		else
		{
			count = N - numsub;
			count += numsubarr.size();
		}

		/*for (int i = 0; i < numarr.size(); i++)
		{
			int num = numarr[i];
			if (!isthereWrongNum(num, wrongNum)) {
				inputNum[i] = num;
				count++;
			}
			else
			{
				int numsub;
				int numplus;
				


			}
		

		}*/

	}
	cout << count;
	

}