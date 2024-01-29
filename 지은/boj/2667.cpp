#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
bool visited[26][26];
vector<int> answer;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = true;
	int cnt = 1;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				continue;
			if (visited[nextY][nextX] || !map[nextY][nextX])
				continue;

			q.push({ nextY, nextX });
			visited[nextY][nextX] = true;
			cnt++;
		}
	}
	answer.push_back(cnt);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j]) {
				bfs(i, j);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int item : answer)
		cout << item << '\n';

	return 0;
}