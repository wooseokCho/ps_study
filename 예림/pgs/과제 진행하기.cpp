#include <bits/stdc++.h>
using namespace std;

typedef struct {
	string name;    // 과제 이름
	int start;      // 시작 시간
	int playtime;   // 남은 시간
} Info;

stack<Info> stk;

bool comp(vector<string> a, vector<string> b) {
	return a[1] < b[1];
}

int getTime(string s) {
	int hour = stoi(s.substr(0, 2));
	int min = stoi(s.substr(3, 2));
	return hour * 60 + min;
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;

	sort(plans.begin(), plans.end(), comp);

	stk.push({ plans[0][0], getTime(plans[0][1]), stoi(plans[0][2]) });

	for (int i = 1; i < plans.size(); i++) {
		int start = getTime(plans[i][1]);

		if (stk.top().start + stk.top().playtime <= start) {
			answer.push_back(stk.top().name);
			int time = start - (stk.top().start + stk.top().playtime);
			stk.pop();

			while (!stk.empty() && time) {
				if (stk.top().playtime > time) {
					stk.top().playtime -= time;
					time = 0;
				}
				else {
					time -= stk.top().playtime;
					answer.push_back(stk.top().name);
					stk.pop();
				}
			}
		}
		else {
			stk.top().playtime -= start - stk.top().start;
		}
		stk.push({ plans[i][0], getTime(plans[i][1]), stoi(plans[i][2]) });
	}

	while (!stk.empty()) {
		answer.push_back(stk.top().name);
		stk.pop();
	}

	return answer;
}