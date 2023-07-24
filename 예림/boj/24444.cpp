#include <bits/stdc++.h>
using namespace std;

int N, M, R, u, v;
vector<vector<int>> graph;
bool visited[100001];
int answer[100001];

void bfs(int sx) {
	queue<int> q;
	int seq = 1;

	visited[sx] = true;
	q.push(sx);

	while (!q.empty()) {
		int x = q.front();
		answer[x] = seq;
		seq++;
		q.pop();

		for (int next : graph[x]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;

	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}