#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	set<int> s;

	for (int i = 0; i < elements.size(); i++) {
		int partialSum = 0;
		for (int j = 0; j < elements.size(); j++) {
			int idx = (i + j) % elements.size();
			partialSum += elements[idx];
			s.emplace(partialSum);
		}
	}

	answer = s.size();

	return answer;
}