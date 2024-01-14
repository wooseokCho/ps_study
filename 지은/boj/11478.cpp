#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	set<string> set;

	string str = "";
	for (int i = 0; i < s.size(); i++) {
		str = "";
		for (int j = i; j < s.size(); j++) {
			str += s[j];
			set.insert(str);
		}
	}
	cout << set.size();

	return 0;
}