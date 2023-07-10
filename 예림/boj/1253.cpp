#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long A[2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	int answer = 0;

	for (int i = 0; i < N; i++) {
		M = A[i];	// 서로 다른 두 수의 합

		int start = 0;
		int end = N - 1;

		while (start < end) {
			if (A[start] + A[end] == M) {
				if (start == i) {
					start++;
				}
				else if (end == i) {
					end--;
				}
				else {
					answer++;
					break;
				}
			}
			else if (A[start] + A[end] < M) {
				start++;
			}
			else {
				end--;
			}
		}
	}

	cout << answer;

	return 0;
}