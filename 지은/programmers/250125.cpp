#include <string>
#include <vector>

using namespace std;

int dh[] = { 0, 1, -1, 0 };
int dw[] = { 1, 0, 0, -1 };

int solution(vector<vector<string>> board, int h, int w) {
	int answer = 0;
	int n = board.size();
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int h_check = h + dh[i];
		int w_check = w + dw[i];

		if (h_check < 0 || h_check >= n || w_check < 0 || w_check >= n) continue;
		if (board[h_check][w_check] == board[h][w])
			count++;
	}

	answer = count;

	return answer;
}