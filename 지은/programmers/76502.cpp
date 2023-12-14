#include <string>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;
	int n = s.size();

	for (int cnt = 0; cnt < n; cnt++) {
		stack<int> stk;

		for (int i = 0; i < s.size(); i++) {
			if (stk.empty()) {
				if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
					stk.push(s[i]);
					break;
				}
			}
			else {
				if ((stk.top() == '(' && s[i] == ')') || 
					(stk.top() == '[' && s[i] == ']') || 
					(stk.top() == '{' && s[i] == '}')) {
					stk.pop();
					continue;
				}
			}
			stk.push(s[i]);
		}

		s += s.front();
		s.erase(s.begin());

		if (stk.empty()) {
			answer++;
		}
	}

	return answer;
}