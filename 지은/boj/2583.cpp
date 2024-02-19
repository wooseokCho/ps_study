#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, cnt;
int paper[101][101];
int rect[101][101];
bool visited[101][101];
vector<int> area;
vector<int> answer;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = true;
	int s = 1;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n)
				continue;
			if (visited[nextY][nextX] || paper[nextY][nextX])
				continue;

			q.push({ nextY, nextX });
			visited[nextY][nextX] = true;
			s++;
		}
	}
	answer.push_back(s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;

		for (int j = y; j < y2; j++) {
			for (int k = x; k < x2; k++) {
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!paper[i][j] && !visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << cnt << '\n';
	for (auto item : answer)
		cout << item << " ";

	return 0;
}