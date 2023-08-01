#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int d[3];
	while (1) {
		for (int i = 0; i < 3; i++)
			cin >> d[i];

		if (d[0] == 0 && d[1] == 0 && d[2] == 0)
			break;

		sort(d, d + 3);

		if (d[2] < d[0] + d[1]) {
			if (d[0] == d[1] && d[1] == d[2])
				cout << "Equilateral" << endl;
			else if (d[0] == d[1] || d[1] == d[2] || d[2] == d[0])
				cout << "Isosceles" << endl;
			else
				cout << "Scalene" << endl;
		}
		else {
			cout << "Invalid" << endl;
		}
	}

	return 0;
}