#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer;

struct Point {
	int x;
	int y;
	int dist;
};

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void dfs(int x, int y, int island) {
	visited[x][y] = true;
	A[x][y] = island;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && A[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, island);
		}
	}
}

void bfs(int island) {
	queue<Point> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == island) {
				visited[i][j] = true;
				q.push({ i, j, 0 });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isOut(nx, ny) || visited[nx][ny]) {
				continue;
			}
			else if (A[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny, dist + 1 });
			}
			else if (A[nx][ny] != island) {
				answer = min(answer, dist);
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	A = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	int island = 1;	// 1. numbering an island
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] && !visited[i][j]) {
				dfs(i, j, island);
				island++;
			}
		}
	}

	answer = INT_MAX;	// 2. finding a bridge (the shortest distance)
	for (int i = 1; i <= island; i++) {
		memset(visited, false, sizeof(visited));
		bfs(i);
	}

	cout << answer;

	return 0;
}