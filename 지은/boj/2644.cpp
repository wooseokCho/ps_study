#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
int visited[101];
int n, m, a, b, answer;

void dfs(int cur, int target, int num) {
	visited[cur] = 1;

	if (cur == target) {
		answer = num;
	}

	for (int i = 0; i < graph[cur].size(); i++) {
		int y = graph[cur][i];
		if (!visited[y]) {
			dfs(y, target, num + 1);
		}
	}
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(a, b, 0);

	if (!answer)
		cout << -1;
	else
		cout << answer;

	return 0;
}