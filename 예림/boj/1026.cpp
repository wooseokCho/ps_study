#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> A;
priority_queue<int> B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push(x);
	}

	for (int i = 0; i < N; i++) {
		cin >> x;
		B.push(x);
	}

	int answer = 0;
	while (!A.empty()) {
		answer += A.top() * B.top();
		A.pop();
		B.pop();
	}

	cout << answer;

	return 0;
}