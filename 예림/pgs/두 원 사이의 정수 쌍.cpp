#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
	long long answer = (r2 - r1 + 1) * 4;   // ¿ø À§ ÁÂÇ¥
	long long inside = 0;   // ¿ø ¾È ÁÂÇ¥

	for (int x = 1; x < r2; x++) {
		long long y2 = floor(sqrt(((long)r2*r2) - ((long)x*x)));
		long long y1 = 1;
		if (x < r1) {
			y1 = ceil(sqrt(((long)r1*r1) - ((long)x*x)));
		}
		inside += (y2 - y1 + 1);
	}

	answer += inside * 4;

	return answer;
}