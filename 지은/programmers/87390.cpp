#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        int col = i % n;
        int row = i / n;
        
        answer.push_back(max(col, row) + 1);
    }
    
    return answer;
}