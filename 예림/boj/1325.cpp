#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[10001];
vector<int> hacking;

void dfs(int now) {
	visited[now] = true;

	for (auto next : graph[now]) {
		if (!visited[next]) {
			hacking[next]++;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	graph.resize(N + 1);
	hacking.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i);
	}

	int max_hacking = *max_element(hacking.begin(), hacking.end());
	for (int i = 1; i <= N; i++) {
		if (hacking[i] == max_hacking) {
			cout << i << " ";
		}
	}

	return 0;
}