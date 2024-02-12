#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = v[0];
	int max_value = v[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
	}

	for (int i = 0; i < n; i++) {
		max_value = max(max_value, dp[i]);
	}
	cout << max_value;

	return 0;
}