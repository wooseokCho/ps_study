#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> minPQ;	// �߰� ������ �۰ų� ����
priority_queue<int, vector<int>, greater<int>> maxPQ;	// �߰� ������ ū

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> x;

		if (minPQ.empty() && maxPQ.empty()) {
			minPQ.push(x);
		}
		else if (minPQ.size() > maxPQ.size()) {
			if (minPQ.top() > x) {
				minPQ.push(x);
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			else {
				maxPQ.push(x);
			}
		}
		else if (minPQ.size() < maxPQ.size()) {
			if (minPQ.top() > x) {
				maxPQ.push(x);
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			else {
				minPQ.push(x);
			}
		}
		else {
			if (minPQ.top() < x) {	// �߰��� ��ȭ
				maxPQ.push(x);
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			else {
				minPQ.push(x);
			}
		}

		cout << minPQ.top() << "\n";
	}

	return 0;
}