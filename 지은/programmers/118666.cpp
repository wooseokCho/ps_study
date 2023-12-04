#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> m;
	int score[] = { 3,2,1,0,1,2,3 };

	for (int i = 0; i < choices.size(); i++) {
		m[survey[i][choices[i] / 4]] += score[choices[i] - 1];
	}

	answer += (m['R'] >= m['T']) ? 'R' : 'T';
	answer += (m['C'] >= m['F']) ? 'C' : 'F';
	answer += (m['J'] >= m['M']) ? 'J' : 'M';
	answer += (m['A'] >= m['N']) ? 'A' : 'N';

	return answer;
}