#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);

	}
	cout << dp[n] << '\n';

	while (n > 1) {
		cout << n << " ";
		if (dp[n] == dp[n - 1] + 1) {
			n--;
		}
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
			n /= 3;
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
			n /= 2;
		}
	}
	cout << 1;

	return 0;
}