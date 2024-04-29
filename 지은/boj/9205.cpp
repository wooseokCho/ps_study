#include <iostream>
#include <cstring>
using namespace std;

struct point {
	int y;
	int x;
};

int t, n;
point sg, store[100], festival;
bool visited[100];

bool dfs(int idx, point start) {
	if (abs(festival.x - start.x) + abs(festival.y - start.y) <= 1000) {
		return true;
	}
	if (idx == n)
		return false;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int d = abs(store[i].x - start.x) + abs(store[i].y - start.y);
			if (d > 1000) continue;
			visited[i] = true;
			if (dfs(idx + 1, store[i])) return true;
		}
	}
	return false;
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> sg.x >> sg.y;

		for (int i = 0; i < n; i++) {
			cin >> store[i].x >> store[i].y;
		}

		cin >> festival.x >> festival.y;

		memset(visited, false, sizeof(visited));
		if (dfs(0, sg))
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}