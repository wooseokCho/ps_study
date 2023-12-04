#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	int xy[] = { 50, 50, 0, 0 };

	for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[i].size(); j++) {
			if (wallpaper[i][j] == '#') {
				xy[0] = min(xy[0], i);
				xy[1] = min(xy[1], j);
				xy[2] = max(xy[2], i + 1);
				xy[3] = max(xy[3], j + 1);
			}
		}
	}

	for (int i = 0; i < 4; i++)
		answer.push_back(xy[i]);

	return answer;
}