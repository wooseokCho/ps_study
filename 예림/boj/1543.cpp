#include <bits/stdc++.h>
using namespace std;

string A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, A);
	getline(cin, B);

	int answer = 0;

	for (int i = 0; i < A.size(); i++) {
		string tmp = A.substr(i, B.size());
		if (tmp == B) {
			answer++;
			i += B.size() - 1;
		}
	}
	
	cout << answer;

	return 0;
}