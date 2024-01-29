#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	long long start = 1;
	long long end = *max_element(v.begin(), v.end());

	long long result = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			if (v[i] > mid)
				sum += v[i] - mid;
		}

		if (sum >= M) {
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