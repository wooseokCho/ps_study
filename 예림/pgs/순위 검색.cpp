#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> um;  // {info, score}
vector<int> answer;

void parsingInfo(string s) {
	string infoArr[4][2] = {    // lang, pos, career, food
		{"-"},
		{"-"},
		{"-"},
		{"-"}
	};

	stringstream ss(s);
	int score;
	ss >> infoArr[0][1] >> infoArr[1][1] >> infoArr[2][1] >> infoArr[3][1] >> score;

	for (int i = 0; i < 2; i++) {    // lang
		for (int j = 0; j < 2; j++) {    // pos
			for (int k = 0; k < 2; k++) {    // career
				for (int l = 0; l < 2; l++) {    // food
					um[infoArr[0][i] + infoArr[1][j] + infoArr[2][k] + infoArr[3][l]].push_back(score);
				}
			}
		}
	}
}

void parsingQueryAndSearch(string s) {
	string queryArr[4];

	stringstream ss(s);
	string tmp; // "and"
	int score;
	ss >> queryArr[0] >> tmp >> queryArr[1] >> tmp >> queryArr[2] >> tmp >> queryArr[3] >> score;

	string key = queryArr[0] + queryArr[1] + queryArr[2] + queryArr[3];
	vector<int> values = um[key];

	int idx = lower_bound(values.begin(), values.end(), score) - values.begin();
	answer.push_back(values.size() - idx);  // Number of people who received score or higher
}

vector<int> solution(vector<string> info, vector<string> query) {

	for (int i = 0; i < info.size(); i++) {
		parsingInfo(info[i]);
	}

	for (auto& m : um) {
		sort(m.second.begin(), m.second.end());
	}

	for (int i = 0; i < query.size(); i++) {
		parsingQueryAndSearch(query[i]);
	}

	return answer;
}