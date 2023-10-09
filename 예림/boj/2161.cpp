#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		cout << q.front() <<" ";
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}
