#include <bits/stdc++.h>
using namespace std;

int T, n, k;
int D[15][15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 14; i++) {
		D[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1];
		}
	}

	cin >> T;

	while (T--) {
		cin >> n >> k;
		cout << D[n][k] << "\n";
	}

	return 0;

}