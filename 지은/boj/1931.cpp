#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	int temp = 0, count = 0;

	for (int i = 0; i < n; i++) {
		int start = v[i].second;
		int end = v[i].first;

		if (start >= temp) {
			temp = end;
			count++;
		}
	}

	cout << count;

	return 0;
}