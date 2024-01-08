#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpSize(vector<int> v1, vector<int> v2) {
	return v1.size() < v2.size();
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> v;
	vector<bool> isVisited(100001, false);

	bool isOpened = false;
	vector<int> num;
	string str = "";

	for (int i = 1; i < s.size() - 1; i++) {
		if (!isOpened && s[i] == '{') {
			isOpened = true;
		}
		else if (isOpened && (s[i] >= '0' && s[i] <= '9')) {
			str.push_back(s[i]);
		}
		else if (isOpened && s[i] == ',') {
			num.push_back(stoi(str));
			str = "";
		}
		else if (isOpened && s[i] == '}') {
			num.push_back(stoi(str));
			v.push_back(num);
			isOpened = false;
			num.clear();
			str = "";
		}
	}

	sort(v.begin(), v.end(), cmpSize);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (isVisited[v[i][j]] == false) {
				isVisited[v[i][j]] = true;
				answer.push_back(v[i][j]);
			}
		}
	}

	return answer;
}