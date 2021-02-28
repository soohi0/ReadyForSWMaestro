// https://acmicpc.net/problem/1260
//성공
#include <Windows.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define VISITED -1

using namespace std;

int N, M, V; //N은 정점,M은 간선 개수,V는 시작할 정점의 번호
int ** graphD;
int ** graphB;


vector<int> BFS(int start);
vector<int> DFS(int start);
void PrintArr(vector<int> arr);
void PrintGraph(int ** gr);
bool isExist(vector<int> arr, int n);



int main() {
	cin >> N >> M >> V;

	graphD = new int *[N + 1];
	graphB = new int *[N + 1];


	for (int i = 0; i <= N; i++) { //N+1 * N+1 행렬
		graphD[i] = new int[N + 1];
		graphB[i] = new int[N + 1];

		for (int j = 0; j <= N; j++) {
			graphD[i][j] = 0; //초기화
			graphB[i][j] = 0; //초기화

		}
	}

	for (int i = 0; i < M; i++) { //값 입력

		int x, y;
		cin >> x;
		cin >> y;
		graphD[x][y] = 1;
		graphD[y][x] = 1; //양방향
		graphB[x][y] = 1;
		graphB[y][x] = 1;
	}

	PrintArr(DFS(V));
	PrintArr(BFS(V));

	Sleep(100000);

}
void PrintGraph(int ** gr) {

	for (int i = 0; i <= N; i++) { //N+1 * N+1 행렬
		for (int j = 0; j <= N; j++) {
			cout << gr[i][j]; //초기화
		}
		cout << endl;
	}
}

vector<int> BFS(int start) {

	queue<int> q; //노드만 넣음

	vector<int> bfs;

	q.push(start);

	while (!q.empty()) {
		int num = q.front();

		for (int i = 0; i <= N; i++) {
			if (graphB[num][i] == 1) {
				q.push(i);
			}
		}
		for (int i = 0; i <= N; i++) {
			graphB[num][i] = VISITED;
		}
		for (int i = 0; i <= N; i++) {
			graphB[i][num] = VISITED;
		}

		if (!isExist(bfs, num)) {
			bfs.push_back(num);
		}
		q.pop();
	}

	return bfs;

}
vector<int> DFS(int start) {

	vector<int > dfs;

	stack<int> stk;

	stk.push(start);

	while (!stk.empty()) {

		int num = stk.top();
		stk.pop();
		if (!isExist(dfs, num)) {
			dfs.push_back(num);
		}

		for (int i = N; i > 0; i--) {
			if (graphD[num][i] == 1) {
				stk.push(i); //자식노드들을 넣음
			}
		}

		//가로막기
		for (int i = 0; i <= N; i++) {
			graphD[num][i] = VISITED;
		}
		//세로막기
		for (int i = 0; i <= N; i++) {
			graphD[i][num] = VISITED;
		}
	}

	return dfs;

}
bool isExist(vector<int> arr, int n) {

	for (int i = 0; i < arr.size(); i++) {
		if (n == arr[i]) {
			return true;
		}
	}
	return false;
}
void PrintArr(vector<int> arr) {

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}
