//https://www.acmicpc.net/problem/5430
//STL Ȱ��
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
			string temp = ""; //���ڸ��� ����
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
				else if (ischar) {//�� ���� ���ڿ����� �Ƚ�
					ischar = false;
					temp += imsi[k];
				}
				else if (!ischar) {//�� ���� ���ڿ��µ� �� ���ڷ� �°��� -> ���ڸ����ų� ���ڸ���
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