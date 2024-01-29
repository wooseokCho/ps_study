#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, k;
	cin >> N >> k;

	long long start = 1;
	long long end = N * N;

	long long result = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}

		if (cnt >= k) {
			result = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << result;

	return 0;
}