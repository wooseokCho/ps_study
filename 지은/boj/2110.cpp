#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[N - 1] - v[0];

	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		int cnt = 1;
		int prev = v[0];

		for (int i = 1; i < N; i++) {
			if (v[i] - prev >= mid) {
				cnt++;
				prev = v[i];
			}
		}

		if (cnt >= C) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << result;

	return 0;
}