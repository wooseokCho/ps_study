#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int temp = arr[0];
	int idx = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= temp) {
			temp = arr[i];
			idx = i;
		}
	}
	arr.erase(arr.begin() + idx);

	if (arr.size() == 0) {
		arr.push_back(-1);
	}
	return arr;

}