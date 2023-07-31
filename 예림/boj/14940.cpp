#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1000][1000];
int dist[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(int tx, int ty) {
	queue<pair<int, int>> q;

	dist[tx][ty] = 0;
	q.push({ tx, ty });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && A[nx][ny] && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int tx, ty;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				tx = i;
				ty = j;
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	bfs(tx, ty);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 0) {	// 예외처리: 벽은 0으로 출력
				dist[i][j] = 0;
			}
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}