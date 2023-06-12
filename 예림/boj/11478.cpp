#include <bits/stdc++.h>
using namespace std;

string S;
set<string> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		string str = "";
		for (int j = i; j < S.size(); j++) {
			str += S[j];
			s.insert(str);
		}
	}

	cout << s.size();

	return 0;
}