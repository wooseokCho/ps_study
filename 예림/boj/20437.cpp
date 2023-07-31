#include <bits/stdc++.h>
using namespace std;

int T, K;
string W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	
	while (T--) {
		cin >> W >> K;

		map<char, vector<int>> m;

		for (int i = 0; i < W.size(); i++) {
			m[W[i]].push_back(i);
		}

		int minLen = 10000;
		int maxLen = 0;

		//for (auto v : m) {
		//	cout << v.first << ": ";
		//	for (int i = 0; i < v.second.size(); i++) {
		//		cout << v.second[i] << ", ";
		//	}
		//	cout << endl;
		//}

		for (auto v : m) {
			if (v.second.size() >= K) {
				for (int i = 0; i <= v.second.size() - K; i++) {
					minLen = min(minLen, v.second[i + K - 1] - v.second[i] + 1);
					maxLen = max(maxLen, v.second[i + K - 1] - v.second[i] + 1);
					cout << W.substr(v.second[i], v.second[i + K -1] - v.second[i] + 1) << endl;
				}
			}
		}

		if (minLen == 10000 && maxLen == 0) {
			cout << "-1\n";
		}
		else {
			cout << minLen << " " << maxLen << "\n";
		}
	}
}