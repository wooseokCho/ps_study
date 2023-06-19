#include <bits/stdc++.h>
using namespace std;

int discounts[8][4];
int cases[7];
bool visited[7];

struct INFO {
	int subscribers;
	int totalSales;
};

struct compare {
	bool operator()(INFO a, INFO b) {
		if (a.subscribers == b.subscribers) {
			return a.totalSales < b.totalSales;
		}
		return a.subscribers < b.subscribers;
	}
};
priority_queue<INFO, vector<INFO>, compare> pq;

void calc(int n, vector<vector<int>> users) {
	int subscribers = 0;
	int totalSales = 0;
	for (int i = 0; i < users.size(); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (users[i][0] > cases[j]) {    // 4 > 3
				continue;
			}
			else {
				sum += discounts[j][cases[j]];
			}
		}

		if (sum < users[i][1]) {
			totalSales += sum;
		}
		else {
			subscribers++;
		}
	}
	pq.push({ subscribers, totalSales });
}

void dfs(int idx, int n, int minRateIdx, vector<vector<int>> users) {
	if (idx == n) {
		calc(n, users);
		return;
	}

	for (int i = minRateIdx; i <= 4; i++) {
		if (!visited[idx]) {
			visited[idx] = true;
			cases[idx] = i;
			dfs(idx + 1, n, minRateIdx, users);
			visited[idx] = false;
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {

	for (int i = 0; i < emoticons.size(); i++) {
		for (int j = 1; j <= 4; j++) {
			discounts[i][j] = emoticons[i] * (10 - j) * 0.1;
		}
	}

	int minRateIdx = 4;
	for (int i = 0; i < users.size(); i++) {
		users[i][0] = (users[i][0] / 10) + (users[i][0] % 10 > 0);
		minRateIdx = min(minRateIdx, users[i][0]);
	}

	dfs(0, emoticons.size(), minRateIdx, users);

	vector<int> answer;
	answer.push_back(pq.top().subscribers);
	answer.push_back(pq.top().totalSales);

	return answer;
}