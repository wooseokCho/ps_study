#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
bool visited[1001];

void dfs(int now) {
	visited[now] = true;
	cout << now << " ";

	for (int next : graph[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();

		for (int next : graph[now]) {
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

	cin >> N >> M >> V;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	dfs(V);
	cout << "\n";

	memset(visited, false, sizeof(visited));
	bfs(V);
	cout << "\n";

	return 0;
}