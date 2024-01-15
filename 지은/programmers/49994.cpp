#include <string>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    map<pair<pair<int, int>, pair<int, int>>, bool> visited;
    int curX = 5, curY = 5;
    
    for (int i = 0; i < dirs.size(); i++) {
        int startX = curX;
        int startY = curY;
        
        if (dirs[i] == 'U') {
            if (curY - 1 < 0)
                continue;
            curY--;
        } else if (dirs[i] == 'D') {
            if (curY + 1 > 10)
                continue;
            curY++;
        } else if (dirs[i] == 'R') {
            if (curX + 1 > 10)
                continue;
            curX++;
        } else {
            if (curX - 1 < 0)
                continue;
            curX--;
        }
        
        if (visited[make_pair(make_pair(startX, startY), make_pair(curX, curY))] == true) {
            continue;
        }
        visited[make_pair(make_pair(startX, startY), make_pair(curX, curY))] = true;
        visited[make_pair(make_pair(curX, curY), make_pair(startX, startY))] = true;
        answer++;
    }
    
    return answer;
}