/* 1546. ЦђБе */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	vector<int> v;

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	double sum = accumulate(v.begin(), v.end(), 0) * 1.0;
	M = *max_element(v.begin(), v.end());
	double answer = sum / M * 100 / N;

	cout << answer;

	return 0;
}