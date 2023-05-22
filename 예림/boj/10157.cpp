#include <bits/stdc++.h>
using namespace std;

int C, R, K;
vector<vector<int>> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> C >> R >> K;

	A = vector<vector<int>>(R, vector<int>(C, 0));

	int i = R - 1, j = 0;
	int num = 1;
	int x = -1, y = -1;

	while (num <= C * R) {
		while (i >= 0 && A[i][j] == 0) {
			if (num == K) {
				x = i;
				y = j;
			}
			A[i--][j] = num++;
		}
		i++;	j++;

		while (j < C && A[i][j] == 0) {
			if (num == K) {
				x = i;
				y = j;
			}
			A[i][j++] = num++;
		}
		i++;	j--;

		while (i < R && A[i][j] == 0) {
			if (num == K) {
				x = i;
				y = j;
			}
			A[i++][j] = num++;
		}
		i--;	j--;

		while (j >= 0 && A[i][j] == 0) {
			if (num == K) {
				x = i;
				y = j;
			}
			A[i][j--] = num++;
		}
		i--;	j++;
	}

	x = R - x;
	y += 1;

	if (K > C * R) {
		cout << "0";
	}
	else {
		cout << y << " " << x;
	}

	return 0;
}