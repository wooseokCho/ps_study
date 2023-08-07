#include <iostream>
using namespace std;

int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int x = (f * b - c * e) / (d * b - a * e);
	int y = (c * d - a * f) / (b * d - a * e);

	cout << x << " " << y;

	return 0;
}