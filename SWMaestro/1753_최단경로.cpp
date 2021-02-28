#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <bitset>
#include <queue>
#include <utility>

//https://www.acmicpc.net/problem/2234

using namespace std;
typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };//남,북,동,서

void PrintArr(int** arr);
void PrintArr(vector<int>* arr);

bool IsallVisited(int ** visited);
int BiggistRoom();
int Merge();
void BFS();
bool IsExist(vector<int> arr, int num);

int Max(int a, int b) {
	if (a > b) return a;
}


int n, m;
int startX, startY = 0;
int roomcnt = 0;

int ** rampart;
int ** visited;

queue<pair<int, int> > q;

int main() {
	// n이 x, m이 y
	cin >> n >> m;

	rampart = new int*[m];
	visited = new int*[m];


	for (int i = 0; i < m; i++) {
		rampart[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> rampart[i][j];
		}
	}
	//방문 안함. 0
	for (int i = 0; i < m; i++) {
		visited[i] = new int[n];
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	BFS();
	cout << roomcnt << endl;//방개수
	cout << BiggistRoom() << endl;
	cout << Merge() << endl;


	Sleep(100000);
}
void PrintArr(int ** arr) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------------" << endl;
}
void PrintArr(vector<int> * arr) {
	for (int i = 0; i < arr->size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {

			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------------" << endl;
}
void BFS(int y, int x) {
	roomcnt++;

	Sleep(100);

	if (IsallVisited(visited)) return;

	q.push(make_pair(y, x));

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;
		//true 1, false 0
		bool i1 = rampart[y][x] & 1;
		bool i2 = rampart[y][x] & 2;
		bool i4 = rampart[y][x] & 4;
		bool i8 = rampart[y][x] & 8;


		if (i1 == 0) {//서
			if (visited[y + moveDir[3].y][x + moveDir[3].x] == 0) {
				//cout << "서" << endl;
				q.push(make_pair(y + moveDir[3].y, x + moveDir[3].x));
			}
		}
		if (i2 == 0) {//북
			if (visited[y + moveDir[1].y][x + moveDir[1].x] == 0) {
				//cout << "북" << endl;
				q.push(make_pair(y + moveDir[1].y, x + moveDir[1].x));
			}
		}
		if (i4 == 0) {//동

			if (visited[y + moveDir[2].y][x + moveDir[2].x] == 0) {
				//cout << "동" << endl;
				q.push(make_pair(y + moveDir[2].y, x + moveDir[2].x));
			}
		}
		if (i8 == 0) {//남
			if (visited[y + moveDir[0].y][x + moveDir[0].x] == 0) {
				//cout << "남" << endl;
				q.push(make_pair(y + moveDir[0].y, x + moveDir[0].x));
			}
		}
		visited[y][x] = roomcnt;

		q.pop();

	}


	PrintArr(visited);
	if (!IsallVisited(visited)) {
		BFS();
	}

}
bool IsallVisited(int** visit) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				startX = j;
				startY = i;
				return false;
			}
		}
	}
	return true;
}
int BiggistRoom() {
	int max = 0;
	for (int l = 1; l <= roomcnt; l++) {
		int cnt = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == l) {
					cnt++;
				}

			}
		}
		if (cnt > max) {
			max = cnt;
		}
	}
	return max;

}
int Merge() {
	//인접한 방끼리의 합이 최대인 수 리턴
	int mergeSize = BiggistRoom();
	//vector<int> * nearby = new vector<int>[roomcnt]; //동적할당 1차원 배열이 벡터타입

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= 8; k *= 2) {
				//int Y = i + moveDir[k].y;
				//int X = j + moveDir[k].x;
				//cout << "i" << Y << " j" << X << endl;

				//if (Y < m && Y >= 0 && X < n && X >= 0) {
				//	if (visited[i][j] == visited[Y][X]) { ; }
				//	else {
				//		if (!IsExist(nearby[visited[i][j] - 1], visited[Y][X])) //옆에꺼가 벡터에 없는숫자면 추가
				//		{
				//			cout << "121" << visited[i][j] << endl;

				//			nearby[visited[i][j] - 1].push_back(visited[Y][X]);
				//		}
				//	}
				//}
				if (rampart[i][j] & k == k) {
					memset(visited, false, sizeof(visited));
					rampart[i][j] = rampart[i][j] - k;
					mergeSize = Max(mergeSize, roomcnt);
					rampart[i][j] = rampart[i][j] + k;
				}
			}
		}

	}

	//PrintArr(nearby);
	return mergeSize;


}
bool IsExist(vector<int> arr, int num) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == num) return true;
	}
	return false;
}