#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		string tmp = "";
		arr[i] = arr1[i] | arr2[i];

		while (tmp.size() != n) {
			if (arr[i] % 2 == 0)
				tmp.push_back(' ');
			else
				tmp.push_back('#');
			arr[i] /= 2;
		}

		reverse(tmp.begin(), tmp.end());
		answer.push_back(tmp);
	}

	return answer;
}