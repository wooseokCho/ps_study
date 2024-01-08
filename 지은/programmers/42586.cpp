#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int count = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        count = 0;
        
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        while (!q.empty() && progresses[q.front()] >= 100) {
            q.pop();
            count++;
        }
        
        if (count != 0) {
            answer.push_back(count);
        }    
    }
    
    return answer;
}