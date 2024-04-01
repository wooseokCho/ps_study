#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> stk;
	int answer = 0;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			stk.pop();

			if (s[i - 1] == '(')
				answer += stk.size();
			else
				answer++;
		}
		else {
			stk.push('(');
		}
	}

	cout << answer;

	return 0;
}