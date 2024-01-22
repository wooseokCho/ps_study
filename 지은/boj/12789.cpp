#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<int> stk;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == cnt)
			cnt++;
		else
			stk.push(num);

		while (!stk.empty() && stk.top() == cnt) {
			stk.pop();
			cnt++;
		}
	}

	if (stk.empty())
		cout << "Nice";
	else
		cout << "Sad";

	return 0;
}