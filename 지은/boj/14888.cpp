#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[12], operations[4];
int max_value = -1000000000, min_value = 1000000000;

void dfs(int cnt, int sum) {
	if (cnt == n - 1) {
		max_value = max(max_value, sum);
		min_value = min(min_value, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operations[i] > 0) {
			operations[i]--;

			if (i == 0) {
				dfs(cnt + 1, sum + nums[cnt + 1]);
			}
			else if (i == 1) {
				dfs(cnt + 1, sum - nums[cnt + 1]);
			}
			else if (i == 2) {
				dfs(cnt + 1, sum * nums[cnt + 1]);
			}
			else {
				dfs(cnt + 1, sum / nums[cnt + 1]);
			}

			operations[i]++;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	for (int i = 0; i < 4; i++)
		cin >> operations[i];

	dfs(0, nums[0]);

	cout << max_value << '\n' << min_value;

	return 0;
}