#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = tolower(new_id[i]);
	}

	for (int i = 0; i < new_id.size();) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			i++;
			continue;
		}
		new_id.erase(new_id.begin() + i);
	}

	for (int i = 1; i < new_id.length();) {
		if (new_id[i] == '.' && new_id[i - 1] == '.') {
			new_id.erase(new_id.begin() + i);
			continue;
		}
		else i++;
	}

	if (new_id.front() == '.') new_id.erase(new_id.begin());
	if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

	if (new_id.empty())
		new_id += 'a';

	if (new_id.length() >= 16) {
		while (new_id.length() != 15) {
			new_id.erase(new_id.begin() + 15);
		}
	}
	if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

	if (new_id.length() <= 2) {
		while (new_id.length() != 3) {
			new_id += new_id.back();
		}
	}
	answer = new_id;

	return answer;
}