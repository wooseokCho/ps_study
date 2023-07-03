#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1001][1001];
int candy[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int maxVal = max(candy[i - 1][j], max(candy[i][j - 1], candy[i - 1][j - 1]));
			candy[i][j] = board[i][j] + maxVal;
		}
	}

	cout << candy[N][M];

	return 0;
}