#include <iostream>
#include <vector>
using namespace std;

bool visited[9];

void dfs(int cnt, int cur, vector<int>& nums, int n, int m) {
	if (cnt == m) {
		for (int item : nums) {
			cout << item << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i <= n; i++) {
		if (!visited[i]) {
			nums.push_back(i);
			visited[i] = true;
		
			dfs(cnt + 1, i, nums, n, m);
			
			visited[i] = false;
			nums.pop_back();
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> nums;
	dfs(0, 1, nums, n, m);

	return 0;
}