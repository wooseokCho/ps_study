#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    map<int, int> m;
    
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i].substr(0, 3) == "D 1") {
            if (pq.empty() || m[pq.top()] == 0)
                continue;
            
            m[pq.top()]--;
            if (pq.top() == pq2.top())
                pq2.pop();
            pq.pop();
        } else if (operations[i].substr(0, 4) == "D -1") {
            if (pq2.empty() || m[pq2.top()] == 0)
                continue;
            
            m[pq2.top()]--;
            if (pq2.top() == pq.top())
                pq.pop();
            pq2.pop();
        } else {
            int num = stoi(operations[i].substr(2, operations[i].size() - 2));
            pq.push(num);
            pq2.push(num);
            m[num]++;
        }
    }
    
    priority_queue<int> pq3;
    priority_queue<int, vector<int>, greater<>> pq4;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second >= 1) {
            pq3.push(it->first);
            pq4.push(it->first);
        }
    }
    
    if (!pq3.empty()) {
        answer.push_back(pq3.top());
        answer.push_back(pq4.top());
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}