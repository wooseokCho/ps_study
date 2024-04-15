#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long answer = 0;
	int n, b, c;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		a[i] -= b;
		answer++;

		if (a[i] > 0) {
			answer += a[i] / c;
			if (a[i] % c != 0) {
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}