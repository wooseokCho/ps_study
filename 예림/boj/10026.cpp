#include <bits/stdc++.h>
using namespace std;

int N;
char A[100][100];
char RG[100][100];	// 적록색약
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void bfs(int x, int y, char c, char Arr[][100]) {
	queue<pair<int, int>> q;

	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && !visited[nx][ny] && Arr[nx][ny] == c) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];

			if (A[i][j] != 'B') {
				RG[i][j] = 'T';
			}
			else {
				RG[i][j] = A[i][j];
			}
		}
	}

	int answer1 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, A[i][j], A);
				answer1++;
			}
		}
	}

	int answer2 = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, RG[i][j], RG);
				answer2++;
			}
		}
	}

	cout << answer1 << " " << answer2;

	return 0;
}