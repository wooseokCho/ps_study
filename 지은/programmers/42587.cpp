#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        if (q.front().first == pq.top()) {
            answer++;
            if (location == q.front().second) break;
            q.pop();
            pq.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}