#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m = { {"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3} };
string flag;

bool cmp(vector<int> v1, vector<int> v2) {
	if (v1[m[flag]] < v2[m[flag]])
		return true;
	return false;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
	vector<vector<int>> answer;
	flag = sort_by;

	for (int i = 0; i < data.size(); i++) {
		if (data[i][m[ext]] < val_ext) {
			answer.push_back(data[i]);
		}
	}

	sort(answer.begin(), answer.end(), cmp);

	return answer;
}