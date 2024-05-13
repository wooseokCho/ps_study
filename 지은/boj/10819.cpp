#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
			sum += abs(a[i] - a[i + 1]);

		answer = max(answer, sum);

	} while (next_permutation(a.begin(), a.end()));

	cout << answer;

	return 0;
}