#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int count, result = 64;
	string board[50];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int y = 0; y < n - 7; y++) {
		for (int x = 0; x < m - 7; x++) {
			count = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if ((i % 2 == j % 2 ? 'W' : 'B') == board[i + y][j + x])
						count++;
				}
			}
			result = min(result, count);
			result = min(result, 64 - count);
		}
	}

	cout << result;


	return 0;
}