#include <iostream>
#include <queue>

using namespace std;

int T, M, N, K;

int grid[50][50]; // 0~49
int c, r;
int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

struct rc{
    int r, c;
};

int main(){

    cin >> T;
    for(int i = 0; i < T; i++){
        int cnt = 0;

        // initialize grid
        for(int j = 0; j<50; j++){
            for(int k = 0; k<50; k++){
                grid[j][k] = 0;
            }
        }
        cin >> M >> N >> K; // c, r, num
        for(int j = 0; j < K; j++){
            // x, y => c, r 상대좌표라 상관 x
            cin >> c >> r;
            grid[r][c] = 1;
        }

        // flood fill
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(grid[j][k] == 0) continue; // visited or empty

                // bfs
                queue<rc> q;
                q.push({j,k});
                grid[j][k] = 0;
                cnt ++;

                while(!q.empty()){
                    rc curRC = q.front(); q.pop();
                    int curR = curRC.r;
                    int curC = curRC.c;

                    int nextR, nextC;
                    for(int l = 0; l<4; l++){
                        nextR = curR + dirR[l];
                        nextC = curC + dirC[l];
                        // if oob
                        if(!(0 <= nextR && nextR < N) || !(0 <= nextC && nextC < M)) continue;
                        if(grid[nextR][nextC] == 0) continue;
                        grid[nextR][nextC] = 0;
                        q.push({nextR, nextC});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}