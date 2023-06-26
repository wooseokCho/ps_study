#include <bits/stdc++.h>
using namespace std;

int n, start;

bool comp(vector<int> &a, vector<int> &b) {
	if (a[0] <= start && b[0] <= start) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {

	n = jobs.size();
	sort(jobs.begin(), jobs.end());

	int answer = jobs[0][1];
	start = jobs[0][0];

	while (jobs.size() > 1) {
		start += jobs[0][1];
		jobs.erase(jobs.begin());

		sort(jobs.begin(), jobs.end(), comp);
		if (start < jobs[0][0]) {
			start = jobs[0][0];
		}
		answer += jobs[0][1] + (start - jobs[0][0]);
	}

	answer = floor(answer / n);

	return answer;
}