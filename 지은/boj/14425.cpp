#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, cnt = 0;
	cin >> N >> M;

	vector<string> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < M; i++) {
		string test;
		cin >> test;
		if (binary_search(s.begin(), s.end(), test))
			cnt++;
	}

	cout << cnt;

	return 0;
}