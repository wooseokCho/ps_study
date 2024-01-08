#include <string>
#include <vector>
#include <algorithm>

#define MAX 8

using namespace std;

int num = 0;
bool isVisited[MAX] = { false, };

int dfs(int count, int k, vector<vector<int>>& dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (!isVisited[i] && k >= dungeons[i][0]) {
            isVisited[i] = true;
            dfs(count + 1, k - dungeons[i][1], dungeons);
            isVisited[i] = false;
        }
    }
    num = max(num, count);
    
    return num;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int count = 0;
    
    answer = dfs(count, k, dungeons);

    return answer;
}