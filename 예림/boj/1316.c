#include <bits/stdc++.h>
using namespace std;

int N;
string word;

bool check() {
	vector<char> alpha(26, false);

	alpha[word[0] - 'a'] = true;

	for (int i = 1; i < word.size(); i++) {
		if (!alpha[word[i] - 'a']) {
			alpha[word[i] - 'a'] = true;
		}
		else {
			if (word[i] == word[i - 1]) {
				continue;
			}
			else {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> word;

		if (check()) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}