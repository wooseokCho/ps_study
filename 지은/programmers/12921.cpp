#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<bool> available(n + 1, true);

	for (int i = 2; i <= n; i++) {
		if (available[i]) {
			for (int j = 2; j*i <= n; j++)
				available[j*i] = false;
			answer++;
		}
	}
	return answer;
}