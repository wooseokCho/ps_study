#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[10][10];
bool visited[10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
typedef tuple<int, int, int> Edge;
vector<Edge> edges;
vector<int> parents;

bool isOut(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void dfs(int x, int y, int island) {
	visited[x][y] = true;
	A[x][y] = island;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isOut(nx, ny) && A[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, island);
		}
	}
}

void distance(int island) {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == island) {
				visited[i][j] = true;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int dist = 0;

			while (1) {
				if (isOut(nx, ny) || visited[nx][ny]) {
					break;
				}
				else if (A[nx][ny] && A[nx][ny] != island) {
					if (dist >= 2) {
						edges.push_back({ island, A[nx][ny], dist });
					}
					break;
				}
				nx += dx[i];
				ny += dy[i];
				dist++;
			}
		}
	}
}

bool compare(Edge &a, Edge &b) {
	return get<2>(a) < get<2>(b);
}

int findParent(int x) {
	if (x == parents[x]) {
		return x;
	}
	return parents[x] = findParent(parents[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parents[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	int island = 0;	// 1. numbering an island
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] && !visited[i][j]) {
				island++;
				dfs(i, j, island);
			}
		}
	}

	for (int i = 1; i <= island; i++) {	// 2. finding a bridge
		memset(visited, false, sizeof(visited));
		distance(i);
	}

	parents.resize(island + 1);
	for (int i = 1; i <= island; i++) {
		parents[i] = i;
	}

	sort(edges.begin(), edges.end(), compare);
	
	int useEdges = 0;	// 3. checking the MST
	int answer = 0;
	for (int i = 0; i < edges.size(); i++) {
		int a = get<0>(edges[i]);
		int b = get<1>(edges[i]);
		int c = get<2>(edges[i]);

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			answer += c;
			useEdges++;
		}
	}

	if (useEdges == island - 1) {	// 4. checking all nodes connections
		cout << answer;
	}
	else {
		cout << -1;
	}

	return 0;
}