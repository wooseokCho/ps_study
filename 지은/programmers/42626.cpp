#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.size() >= 2 && pq.top() < K) {
		int sum = pq.top();
		pq.pop();
		sum += pq.top() * 2;
		pq.pop();

		pq.push(sum);
		answer++;
	}

	if (pq.top() < K) {
		answer = -1;
	}

	return answer;
}