#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<string> num = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string tmp = "";

	for (char c : s) {
		if (isdigit(c)) answer = answer * 10 + c - '0';
		else tmp.push_back(c);

		for (int i = 0; i <= 9; i++) {
			if (num[i] == tmp) {
				answer = answer * 10 + i;
				tmp = "";
				break;
			}
		}
	}

	return answer;
}