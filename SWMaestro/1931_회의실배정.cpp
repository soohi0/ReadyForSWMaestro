#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

//https://www.acmicpc.net/problem/1931
//����
using namespace std;
int N;
int meetingCount = 1;
vector<pair<int, int> > meetingTime;
int startT, endT;
int timeIndex = 0;
int cmpIndex = 1;
void PrintVec();
void eraseVec();
int main() {
	cin >> N;


	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meetingTime.push_back(make_pair(end, start));
	}



	sort(meetingTime.begin(), meetingTime.end()); //end �������� ����
	startT = meetingTime[0].second;
	endT = meetingTime[0].first;;

	PrintVec();

	while (timeIndex < N || cmpIndex < N + 1) {

		eraseVec();

		timeIndex = cmpIndex;
		cmpIndex++;
		PrintVec();
	}

	cout << meetingCount << endl;

	Sleep(1000000000);

}
void PrintVec() {
	for (int i = 0; i < meetingTime.size(); i++) {
		pair<int, int> sd;
		sd = meetingTime[i];
		cout << sd.first << " , " << sd.second << endl;

	}
	cout << " T " << timeIndex << " c " << cmpIndex << endl;
	cout << "==================" << endl;

}
void eraseVec() {
	if (cmpIndex > N - 1) {
		return;
	}

	pair<int, int> imsi;
	imsi = meetingTime[cmpIndex];
	if (endT > imsi.second) {
		cmpIndex++;
	}
	else {
		meetingCount++;
		endT = meetingTime[cmpIndex].first;
		startT = meetingTime[cmpIndex].second;

		return;
	}
	eraseVec();
}



//second �������� �������� sort.������ �ִٸ� ���������°Ÿ� ���� ����
//second�� �߿��� ���� ���� �����ϰ� ������ ȸ�� ����, ȸ�� �� ����, ����
//�� ȸ�� �߰��� �����ϴ� ȸ�� ������ ����
//������ �߿��� �ݺ�.

//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int start, end;
//		cin >> start >> end;
//		
//	}
//}