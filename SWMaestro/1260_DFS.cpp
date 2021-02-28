// https://acmicpc.net/problem/1260
//����
#include <Windows.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define VISITED -1

using namespace std;

int N, M, V; //N�� ����,M�� ���� ����,V�� ������ ������ ��ȣ
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


	for (int i = 0; i <= N; i++) { //N+1 * N+1 ���
		graphD[i] = new int[N + 1];
		graphB[i] = new int[N + 1];

		for (int j = 0; j <= N; j++) {
			graphD[i][j] = 0; //�ʱ�ȭ
			graphB[i][j] = 0; //�ʱ�ȭ

		}
	}

	for (int i = 0; i < M; i++) { //�� �Է�

		int x, y;
		cin >> x;
		cin >> y;
		graphD[x][y] = 1;
		graphD[y][x] = 1; //�����
		graphB[x][y] = 1;
		graphB[y][x] = 1;
	}

	PrintArr(DFS(V));
	PrintArr(BFS(V));

	Sleep(100000);

}
void PrintGraph(int ** gr) {

	for (int i = 0; i <= N; i++) { //N+1 * N+1 ���
		for (int j = 0; j <= N; j++) {
			cout << gr[i][j]; //�ʱ�ȭ
		}
		cout << endl;
	}
}

vector<int> BFS(int start) {

	queue<int> q; //��常 ����

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
				stk.push(i); //�ڽĳ����� ����
			}
		}

		//���θ���
		for (int i = 0; i <= N; i++) {
			graphD[num][i] = VISITED;
		}
		//���θ���
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
