#include <iostream>
using namespace std;

int main() {
	int n, p[1000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += p[i] * (n - i);

	cout << sum;

	return 0;
}