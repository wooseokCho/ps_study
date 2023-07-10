#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
int A[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int answer = 0;
	int start = 0;
	int end = 0;
	long long sum = 0;

	while (end <= N) {
		if (sum <= M) {
			if (sum == M) {
				answer++;
			}
			sum += A[end++];
		}
		else {
			sum -= A[start++];
		}
	}

	cout << answer;

	return 0;
}