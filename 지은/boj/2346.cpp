#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << dq.front() << " ";
	dq.pop_front();
	
	int idx = 0;
	while (!dq.empty()) {
		for (int i = 1; i < abs(v[idx]); i++) {
			if (v[idx] > 0) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		if (v[idx] > 0) {
			cout << dq.front() << " ";
			idx = dq.front() - 1;
			dq.pop_front();
		}
		else {
			cout << dq.back() << " ";
			idx = dq.back() - 1;
			dq.pop_back();
		}
	}

	return 0;
}