#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

	int inputNum = 1;
	cin >> inputNum;
	string * inputStr = new string[inputNum];
	for (int i = 0; i < inputNum; i++) {
		cin >> inputStr[i];
	}
	bool isCheck = false;
	int checkCount = 0;
	//�ߺ��� ���� ���ڿ��� �����
	//���ڿ��� Ž���Ͽ� �ߺ��Ǹ� bool ���� false�� �ٲ۴�

	for (int i = 0; i < inputNum; i++) {
		string imsiStr = "";
		for (int j = 0; j < inputStr[i].size(); j++) {

			//���� �ӽ� str[j-1]�� �ִ°Ŷ� ���ٸ� pass
			if (j != 0 && imsiStr[imsiStr.size() - 1] == inputStr[i][j]) {


			}
			else {
				//�׷��� �ʴٸ� �߰�
				imsiStr += inputStr[i][j];
			}
		}
		//cout << imsiStr<<endl;
		for (int k = 0; k < imsiStr.size(); k++) {
			for (int l = k + 1; l < imsiStr.size(); l++) {
				if (imsiStr[k] == imsiStr[l]) {//������ ������ �ִٸ�
					isCheck = true;
					break;
				}
			}
		}
		if (!isCheck) {
			checkCount++;
		}
		else {
			isCheck = false;
		}

	}
	cout << checkCount << endl;
	Sleep(100000000);
}

