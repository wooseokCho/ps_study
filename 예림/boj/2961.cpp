#include <bits/stdc++.h>
using namespace std;

int N;
int A[10][2];
int answer;

void dfs(int idx, int S, int B, int cnt) {
	if (idx == N) {
		if (cnt > 0) {	// 적어도 하나 이상의 재료 사용
			answer = min(answer, abs(S - B));
		}
		return;
	}

	dfs(idx + 1, S * A[idx][0], B + A[idx][1], cnt + 1);	// 선택 O
	dfs(idx + 1, S, B, cnt);	// 선택 X
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> A[i][j];
		}
	}

	answer = 1000000000;

	dfs(0, 1, 0, 0);

	cout << answer;

	return 0;
}