#include <bits/stdc++.h>
using namespace std;

int N;
int A[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void bfs(int x, int y, int height) {
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

			if (!isOut(nx, ny) && !visited[nx][ny] && A[nx][ny] > height) {
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

	int minVal = 100;
	int maxVal = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];

			minVal = min(minVal, A[i][j]);
			maxVal = max(maxVal, A[i][j]);
		}
	}

	int answer = 1;

	for (int height = minVal; height <= maxVal; height++) {
		int zone = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] > height && !visited[i][j]) {
					bfs(i, j, height);
					zone++;
				}
			}
		}
		answer = max(answer, zone);
	}

	cout << answer;

	return 0;
}