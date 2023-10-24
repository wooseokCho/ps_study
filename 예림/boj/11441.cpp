#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
int A[100001];
int S[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		S[i] = S[i - 1] + A[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << S[b] - S[a - 1] << "\n";
	}

	return 0;
}