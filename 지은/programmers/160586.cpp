#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	int minCount = 101;
	int sum = 0;

	for (int i = 0; i < targets.size(); i++) {
		sum = 0;
		for (int j = 0; j < targets[i].size(); j++) {
			minCount = 101;
			for (int k = 0; k < keymap.size(); k++) {
				if (keymap[k].find(targets[i][j]) != string::npos) {
					minCount = min(minCount, (int)keymap[k].find(targets[i][j]) + 1);
				}
			}
			if (minCount == 101) break;
			else sum += minCount;
		}
		if (minCount == 101) answer.push_back(-1);
		else answer.push_back(sum);
	}

	return answer;
}