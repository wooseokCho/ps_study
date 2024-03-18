#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int cnt;
vector<int> graph[MAX];

void bfs(int v1, int v2) {
    queue<int> q;
    bool visited[MAX] = { false, };

    q.push(v1);
    visited[v1] = visited[v2] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) continue;

            cnt++;
            q.push(next);
            visited[next] = true;
        }
        
    }

}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;

    for (int i = 0; i < wires.size(); i++) {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++) {
        cnt = 1;
        int v1 = wires[i][0];
        int v2 = wires[i][1];

        bfs(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
    }

    return answer;
}