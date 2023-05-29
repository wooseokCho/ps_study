#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] + n > 'Z' ? s[i] += n - 'Z' + 'A' - 1 : s[i] += n;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] + n > 'z' ? s[i] += n - 'z' + 'a' - 1 : s[i] += n;
		}
	}
	answer = s;

	return answer;
}