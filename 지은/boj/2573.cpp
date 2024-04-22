#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, year, cnt;
int snow[301][301];
int melt[301][301];
bool visited[301][301];
queue<pair<int, int>> q;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

void addYear() {
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (snow[next_y][next_x] != 0)
				continue;

			melt[cur_y][cur_x]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			snow[i][j] = (snow[i][j] - melt[i][j] > 0) ? snow[i][j] - melt[i][j] : 0;
		}
	}
	year++;
}

void getCnt(int y, int x) {
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (visited[next_y][next_x] || snow[next_y][next_x] == 0)
				continue;

			q.push({ next_y, next_x });
			visited[next_y][next_x] = true;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> snow[i][j];
		}
	}

	while (true) {
		memset(melt, 0, sizeof(melt));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (snow[i][j] > 0) {
					q.push({ i,j });
				}
			}
		}

		addYear();

		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && snow[i][j] > 0) {
					getCnt(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << year;
			break;
		}
		else if (cnt == 0) {
			cout << 0;
			break;
		}
	}

	return 0;
}