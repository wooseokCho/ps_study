#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c, answer;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
char board[20][20];
bool alphabet[26];

void dfs(int cnt, int y, int x) {
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c)
			continue;

		if (!alphabet[board[next_y][next_x] - 'A']) {
			alphabet[board[next_y][next_x] - 'A'] = true;

			dfs(cnt + 1, next_y, next_x);

			alphabet[board[next_y][next_x] - 'A'] = false;
		}
	}

	if (answer < cnt)
		answer = cnt;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			board[i][j] = str[j];
		}
	}

	alphabet[board[0][0] - 'A'] = true;
	dfs(1, 0, 0);

	cout << answer;

	return 0;
}