#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0;

	sort(score.begin(), score.end(), greater<int>());

	for (int i = 0; i < score.size() / m; i++) {
		vector<int> v(score.begin() + i * m, score.begin() + (i + 1) * m);
		answer += v[v.size() - 1] * m;
	}

	return answer;
}