#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	string str = "";

	s.front() = toupper(s.front());

	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == ' ') {
			s[i] = toupper(s[i]);
		}
		else {
			s[i] = tolower(s[i]);
		}
	}

	answer = s;

	return answer;
}