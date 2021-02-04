#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
//int fibonacci(int n) {
//	if (n == 0) {
//		printf("0\n");
//		return 0;
//	}
//	else if (n == 1) {
//		printf("1\n");
//		return 1;
//	}
//	else {
//		cout << "fibonacci(" << n << ")" << endl;
//		return fibonacci(n - 1) + fibonacci(n-2);
//	}
//}
int main()
{
	int T;
	scanf("%d", &T);
	vector<pair<int, int> > v(41);
	v[0] = make_pair(1, 0);
	v[1] = make_pair(0, 1);
	for (int i = 2; i < 41; i++)
	{
		v[i].first = v[i - 1].first + v[i - 2].first;
		v[i].second = v[i - 1].second + v[i - 2].second;
	}
	vector<int> vidx(T);
	for (int i = 0; i < T; i++)
	{
		int num;
		scanf("%d", &num);
		vidx[i] = num;
	}
	for (int i = 0; i < T; i++)
	{
		printf("%d %d\n", v[vidx[i]].first, v[vidx[i]].second);
	}

}
//0 : 1, 0
//1 : 0, 1
//2 : 1, 1
//3 : 1, 2
//4 : 2, 3
//5 : 3, 5
