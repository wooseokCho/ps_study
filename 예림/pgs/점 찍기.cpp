#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
	long long answer = 0;

	for (int x = 0; x <= d; x += k) {
		long long y = floor(sqrt(((long)d*d) - ((long)x*x)) / k);
		answer += y + 1;
	}

	return answer;
}