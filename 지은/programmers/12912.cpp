#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
	long long answer = 0;
	int nTmp = 0;
	if (a > b) {
		nTmp = b;
		b = a;
		a = nTmp;
	}
	for (int i = a; i <= b; i++)
		answer += i;

	return answer;
}