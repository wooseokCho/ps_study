#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".")
			break;

		stack<char> stk;
		int flag = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				stk.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!stk.empty() && stk.top() == '(') {
					stk.pop();
				}
				else {
					flag = 1;
					break;
				}
			}
			else if (str[i] == ']') {
				if (!stk.empty() && stk.top() == '[') {
					stk.pop();
				}
				else {
					flag = 1;
					break;
				}
			}
		}

		if (!flag && stk.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}