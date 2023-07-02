#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> S, E, L;
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct {
	int x;
	int y;
	int dist;
}Info;

bool isOut(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}

int bfs(vector<string> maps, int sx, int sy, int tx, int ty) {
	queue<Info> q;
	visited[sx][sy] = true;
	q.push({ sx, sy, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		if (x == tx && y == ty) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isOut(nx, ny) && maps[nx][ny] != 'X' && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny, dist + 1 });
			}
		}
	}

	return -1;
}

int solution(vector<string> maps) {

	n = maps.size();
	m = maps[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] == 'S') {
				S = make_pair(i, j);
			}
			if (maps[i][j] == 'E') {
				E = make_pair(i, j);
			}
			if (maps[i][j] == 'L') {
				L = make_pair(i, j);
			}
		}
	}

	int S_to_L = bfs(maps, S.first, S.second, L.first, L.second);

	memset(visited, false, sizeof(visited));
	int L_to_E = bfs(maps, L.first, L.second, E.first, E.second);

	int answer = -1;

	if (S_to_L != -1 && L_to_E != -1) {
		answer = S_to_L + L_to_E;
	}

	return answer;
}