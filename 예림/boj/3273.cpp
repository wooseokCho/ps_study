#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}

	cin >> x;

	sort(a.begin(), a.end());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (binary_search(a.begin(), a.end(), x - a[i])) {
			answer++;
		}
	}

	cout << answer / 2;

	return 0;
}