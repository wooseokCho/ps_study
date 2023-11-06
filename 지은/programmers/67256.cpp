#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lNum = 10, rNum = 12;
    
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L";
			lNum = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R";
			rNum = numbers[i];
		}
		else {
			if (numbers[i] == 0)
				numbers[i] = 11;

			int leftLen = abs(numbers[i] - lNum) / 3 + abs(numbers[i] - lNum) % 3;
			int rightLen = abs(numbers[i] - rNum) / 3 + abs(numbers[i] - rNum) % 3;

			if (rightLen < leftLen) {
				answer += "R";
				rNum = numbers[i];
			}
			else if (rightLen > leftLen) {
				answer += "L";
				lNum = numbers[i];
			}
			else {
				if (hand == "left") {
					answer += "L";
					lNum = numbers[i];
				}
				else {
					answer += "R";
					rNum = numbers[i];
				}

			}
		}
	}

	return answer;
}