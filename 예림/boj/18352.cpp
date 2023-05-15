#include <bits/stdc++.h>
using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
bool visited[300001];
vector<int> answer;

struct Node {
	int node;
	int dist;
};

void bfs(int start) {
	queue<Node> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		int now = q.front().node;
		int dist = q.front().dist;
		q.pop();

		if (dist == K) {
			answer.push_back(now);
		}

		for (auto next : graph[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> X;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}

	bfs(X);

	if (answer.empty()) {
		cout << -1;
	}
	else {
		sort(answer.begin(), answer.end());
		for (auto ans : answer) {
			cout << ans << "\n";
		}
	}

	return 0;
}