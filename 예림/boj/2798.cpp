#include <bits/stdc++.h>
using namespace std;

int N, M;
int card[100];
bool visited[100];
int answer;

void dfs(int idx, int sum, int depth) {
	if (sum > M) {
		return;
	}
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	dfs(0, 0);

	cout << answer;

	return 0;
}