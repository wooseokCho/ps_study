#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = -1;
	long long sum = 0;
	for (int i = 0; i < count; i++)
		sum += price * (i + 1);

	if (sum <= money)
		answer = 0;
	else
		answer = abs(money - sum);

	return answer;
}