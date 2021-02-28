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
	//중복을 없앤 문자열을 만든다
	//문자열을 탐색하여 중복되면 bool 값을 false로 바꾼다

	for (int i = 0; i < inputNum; i++) {
		string imsiStr = "";
		for (int j = 0; j < inputStr[i].size(); j++) {

			//만약 임시 str[j-1]에 있는거랑 같다면 pass
			if (j != 0 && imsiStr[imsiStr.size() - 1] == inputStr[i][j]) {


			}
			else {
				//그렇지 않다면 추가
				imsiStr += inputStr[i][j];
			}
		}
		//cout << imsiStr<<endl;
		for (int k = 0; k < imsiStr.size(); k++) {
			for (int l = k + 1; l < imsiStr.size(); l++) {
				if (imsiStr[k] == imsiStr[l]) {//이전에 같은게 있다면
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

