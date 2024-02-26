#include <iostream>
#include <queue>
using namespace std;

int t, l;
int dx[] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[] = { 2,-2,1,-1,2,-2,1,-1 };

int bfs(int startY, int startX, int destY, int destX) {
	int dist[301][301] = { 0, };
	bool visited[301][301] = { false, };
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = true;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		if (curY == destY && curX == destX)
			break;
		for (int i = 0; i < 8; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= l || nextX < 0 || nextX >= l || visited[nextY][nextX])
				continue;

			q.push({ nextY, nextX });
			visited[nextY][nextX] = true;
			dist[nextY][nextX] = dist[curY][curX] + 1;
		}
	}

	return dist[destY][destX];
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> l;

		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		cout << bfs(y, x, y2, x2) << '\n';
	}

	return 0;
}