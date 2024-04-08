#include <iostream>
#include <algorithm>
using namespace std;

int dp[15];
int t[15];
int p[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + t[i]; j <= n; j++) {
			dp[j] = max(dp[j], dp[i] + p[i]);
		}
	}
    
	cout << dp[n];

	return 0;
}