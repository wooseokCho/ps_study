#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
	int answer = 0;

	vector<string> available = { "aya", "ye", "woo", "ma" };

	for (int i = 0; i < babbling.size(); i++) {
		int flag = 0;
		bool result = true;
		string str = babbling[i];
		for (int j = 0; j < str.length(); j++) {
			if (str.substr(j, available[0].length()) == available[0] && flag != 1) {
				flag = 1;
				j += available[0].length() - 1;
			}
			else if (str.substr(j, available[1].length()) == available[1] && flag != 2) {
				flag = 2;
				j += available[1].length() - 1;
			}
			else if (str.substr(j, available[2].length()) == available[2] && flag != 3) {
				flag = 3;
				j += available[2].length() - 1;
			}
			else if (str.substr(j, available[3].length()) == available[3] && flag != 4) {
				flag = 4;
				j += available[3].length() - 1;
			}
			else {
				result = false;
				break;
			}
		}
		if (result)
			answer++;
	}
	return answer;
}