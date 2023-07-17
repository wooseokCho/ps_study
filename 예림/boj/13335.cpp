#include <bits/stdc++.h>
using namespace std;

int N, W, L;
int A[1000];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> W;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int answer = 0;
	int idx = 0;
	int sum = 0;	// 다리 위에 있는 트럭 무게의 합

	while (idx < N) {
		if (q.size() >= L) {
			sum -= q.front();
			q.pop();
		}

		if (sum + A[idx] <= W) {
			q.push(A[idx]);
			sum += A[idx];
			idx++;
		}
		else {
			q.push(0);
		}

		answer++;
	}

	answer += L;

	cout << answer;

	return 0;
}