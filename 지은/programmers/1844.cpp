#include <vector>
#include <queue>

using namespace std;

bool isVisited[101][101];
int dist[101][101];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int solution(vector<vector<int>> maps) {
    int answer = 0;
    queue<pair<int,int>> q;
    
    int n = maps.size();
    int m = maps[0].size();
    
    q.push({0,0});
    isVisited[0][0] = true;
    dist[0][0] = 1;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int tx = curX + dx[i];
            int ty = curY + dy[i];
            
            if (tx < 0 || ty < 0 || tx >= n || ty >= m)
                continue;
            
             if (!maps[tx][ty])
                continue;
            
            if (isVisited[tx][ty])
                continue;
            
            q.push({tx, ty});
            isVisited[tx][ty] = true; 
            dist[tx][ty] = dist[curX][curY] + 1;
        }
    }
    
    answer = (dist[n-1][m-1]) ? dist[n-1][m-1] : -1;
    
    return answer;
}