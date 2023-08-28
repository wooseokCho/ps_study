#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w = 0;
    int h = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        w = max(w, max(sizes[i][0], sizes[i][1]));
        h = max(h, min(sizes[i][0], sizes[i][1]));
    }
    
    answer = w * h;
    return answer;
}