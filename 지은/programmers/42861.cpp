#include <vector>
#include <algorithm>

using namespace std;

vector<int> node(101);

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int findParent(int x) {
    if (node[x] == x)
        return node[x];
    return node[x] = findParent(node[x]);
} 

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        node[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];
        
        if (start != end) {
            answer += cost;
            node[end] = start;
        }
    }
    
    return answer;
}