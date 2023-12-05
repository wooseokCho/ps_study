class Solution {
public:
	static bool comp(pair<string, string> &a, pair<string, string> &b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}

	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> digit;
		vector<pair<string, string>> letter;
		vector<string> answer;

		for (string log : logs) {
			stringstream ss(log);
			string idx;
			ss >> idx;

			string str = log.substr(idx.size() + 1);

			if (isdigit(str[0])) {
				digit.push_back(log);
			}
			else {
				letter.push_back({ idx, str });
			}
		}

		sort(letter.begin(), letter.end(), comp);

		for (int i = 0; i < letter.size(); i++) {
			string log = letter[i].first + " " + letter[i].second;
			answer.push_back(log);
		}

		for (int i = 0; i < digit.size(); i++) {
			answer.push_back(digit[i]);
		}

		return answer;
	}
};