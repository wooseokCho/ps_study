#include <bits/stdc++.h>
using namespace std;

int K, N;
int A[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	for (int i = 1; i <= K; i++) {
		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> A[j];
		}

		sort(A, A + N);

		int minVal = A[0];
		int maxVal = A[N - 1];
		int diff = 0;

		for (int j = 1; j < N; j++) {
			diff = max(diff, A[j] - A[j - 1]);
		}

		cout << "Class " << i << "\n";
		cout << "Max " << maxVal << ", Min " << minVal << ", Largest gap " << diff << "\n";
	}

	return 0;
}