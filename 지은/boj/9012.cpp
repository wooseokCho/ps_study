#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		string answer = "YES";
		stack<char> stk;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ')') {
				if (stk.empty()) {
					answer = "NO";
					break;
				}
				else {
					stk.pop();
					continue;
				}
			}
			stk.push('(');
		}

		if (!stk.empty())
			answer = "NO";

		cout << answer << '\n';
	}

	return 0;
}