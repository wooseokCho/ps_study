#include <bits/stdc++.h>
using namespace std;

int N, K;
int D[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		D[i][0] = 1;
		D[i][i] = 1;
		D[i][1] = i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % 10007;
		}
	}

	cout << D[N][K];

	return 0;
}