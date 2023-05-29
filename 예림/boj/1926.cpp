#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[501][501];
bool visited[501][501];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isOut(int x, int y) {
	return (x < 0 || x > n || y < 0 || y > m);
}

int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	visited[sx][sy] = true;
	q.push({ sx, sy });
	int area = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && !visited[nx][ny] && A[nx][ny]) {
				visited[nx][ny] = true;
				area++;
				q.push({ nx, ny });
			}
		}
	}

	return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	int cnt = 0;
	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] && !visited[i][j]) {
				maxArea = max(maxArea, bfs(i, j));
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	cout << maxArea << "\n";

	return 0;
}