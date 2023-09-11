#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
	vector<int> answer;

	int gcdNum = gcd(max(n, m), min(n, m));
    int lcmNum = (n * m) / gcdNum;
    
	answer.push_back(gcdNum);
	answer.push_back(lcmNum);

	return answer;
}