#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<int> v;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	long long start = 1;
	long long end = *max_element(v.begin(), v.end());

	long long result = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;

		for (int i = 0; i < K; i++) {
			sum += (v[i] / mid);
		}

		if (sum >= N) {
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