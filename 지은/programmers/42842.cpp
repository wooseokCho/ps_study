#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int carpet = brown + yellow;

	for (int h = 3;; h++) {
		if (carpet % h == 0) {
			int w = carpet / h;
			if ((w - 2) * (h - 2) == yellow) {
				answer.push_back(w);
				answer.push_back(h);
				break;
			}
		}
	}

	return answer;
}