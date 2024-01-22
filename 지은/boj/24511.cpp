#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	deque<int> dq;
	vector<int> flag(n);
	for (int i = 0; i < n; i++) {
		cin >> flag[i];
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (!flag[i])
			dq.push_back(num);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		dq.push_front(num);
		cout << dq.back() << " ";
		dq.pop_back();
	}

	return 0;
}