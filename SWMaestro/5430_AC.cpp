//https://www.acmicpc.net/problem/5430
//STL 활용
#include <Windows.h>
#include <iostream>
#include <vector>
#include<deque>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int T;
	cin >> T;

	deque<int> deq;

	for (int i = 0; i < T; i++) {
		string function = "";
		cin >> function;
		for (int j = 0; j < function.size(); j++) {
			int size;
			cin >> size;
			string imsi = "";
			cin >> imsi;
			string temp = ""; //두자리수 숫자
			bool ischar = true;
			for (int k = 0; k < imsi.size(); k++) {
				if (imsi[k] == '[' || imsi[k] == ']' || imsi[k] == ',') {
					ischar = true;
					if (temp != "") {
						stringstream ss(temp);
						int atoi;
						ss >> atoi;
						deq.push_back(atoi);
						temp = "";
					}
				}
				else if (ischar) {//그 전에 문자였으니 안심
					ischar = false;
					temp += imsi[k];
				}
				else if (!ischar) {//그 전에 숫자였는데 또 숫자로 온거임 -> 두자리수거나 세자리수
					temp += imsi[k];
				}
			}
			for (int k = 0; k < deq.size(); k++) {
				cout << deq.front() << endl;
				deq.pop_front();

			}

			if (function[j] == 'R') {

			}
			else if (function[j] == 'D') {

			}
		}
	}
	Sleep(100000000);
}