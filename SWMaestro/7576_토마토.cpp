//성공
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
queue<pair<int, int> > startTmt;
int n, m;
int ** tomato;

int BFS();
void Move(int x, int y);
bool isRipe();

int main() {

	vector<pair<int, int> > notTmt;
	cin >> m >> n; //m이 가로 n이 세로
	tomato = new int*[n];
	for (int i = 0; i < n; i++) {
		tomato[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1) {

				startTmt.push(pair<int, int>(i, j));//토마토 시작 위치 저장
				//cout << startTmt[startTmt.size()-1].first << startTmt[startTmt.size() - 1].second;
				//cout << qs[0].front().first << qs[0].front().first;
			}
			else if (tomato[i][j] == -1) {
				notTmt.push_back(make_pair(i, j));//토마토가 못가는 위치 저장
			}
		}
	}
	int day = BFS();
	//cout << "day : " << day << endl;
	if (isRipe()) {
		cout << day - 1 << endl;;
	}
	else {
		cout << -1 << endl;;
	}
	//cout << day << endl;

	//print

	Sleep(10000000000000);

}
int BFS() {
	int day = 0;
	if (startTmt.empty()) return -1;

	while (!startTmt.empty()) {
		int qSize = startTmt.size();
		for (int i = 0; i < qSize; i++) {
			int y = startTmt.front().first;
			int x = startTmt.front().second;

			//cout << y << "  x : " << x << endl;
			int nextX = x + 1;
			int nextY = y + 1;
			int beforeX = x - 1;
			int beforeY = y - 1;

			/*Move(x, y-1);
			Move(x - 1, y);

			Move(x, y + 1);

			cout << "22  " << tomato[y-1][x] << endl;
			Move(x+1, y);*/

			for (int i = 0; i < 4; i++)

			{

				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;
				Move(nextX, nextY);

			}
			startTmt.pop();


		}
		day++;
	}
	for (int i = 0; i < n; i++) {
		//tomato[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cout << tomato[i][j] << " ";
		}
		cout << endl;
	}
	return day;

}
void Move(int x, int y) {
	//cout << "ss"<<  "  x : " << x << "  y: " << y <<endl;
	if (!(y < n && y >= 0 && x < m && x >= 0)) {
		return;
	}
	if (tomato[y][x] == 0) {
		tomato[y][x] = 1;
		//cout << "  x : " << x << "  y: "<< y << endl;

		startTmt.push(pair<int, int>(y, x));
	}
	else if (tomato[y][x] == 1) {//이미 1이면
		//cout << "??" << endl;
		return;
	}
	else if (tomato[y][x] == -1) {
		//cout << "?!!" << endl;

		return;
	}
	else {
		//cout << "!!!!" << endl;
		return;
	}
	//cout << "empty?  " << startTmt.empty() << endl;
	//Sleep(5000);
}
bool isRipe() {
	bool* ripe = new bool[n * m];
	//ripe = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1 || tomato[i][j] == -1) {
				ripe[n * i + j] = true;

			}
			else {
				ripe[n * i + j] = false;
			}

		}
	}
	for (int i = 0; i < n * m; i++)
	{
		cout << "ripe[i]   " << ripe[i] << "  i " << i << endl;
		if (ripe[i] == false) {
			return false;
		}
	}
	//모두 true 라면
	return true;

}