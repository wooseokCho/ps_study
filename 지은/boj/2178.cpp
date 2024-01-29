#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int miro[101][101];
int dist[101][101];
bool visited[101][101];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int startY, int startX) {
	queue<pair<int, int>> q;
	visited[startY][startX] = true;
	q.push({ startY, startX });
	dist[startY][startX] = 1;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
				continue;
			if (visited[nextY][nextX] || !miro[nextY][nextX])
				continue;

			q.push({ nextY, nextX });
			visited[nextY][nextX] = true;
			dist[nextY][nextX] = dist[curY][curX] + 1;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str = "";
		cin >> str;

		for (int j = 0; j < M; j++)
			miro[i][j] = str[j] - '0';
	}

	bfs(0, 0);

	cout << dist[N - 1][M - 1];

	return 0;
}