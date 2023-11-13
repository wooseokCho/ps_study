#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> math = {{1, 2, 3, 4, 5},
                       {2, 1, 2, 3, 2, 4, 2, 5},
                       {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int mCnt1 = 0;
    int mCnt2 = 0;
    int mCnt3 = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (math[0][i % math[0].size()] == answers[i]) mCnt1++;
        if (math[1][i % math[1].size()] == answers[i]) mCnt2++;
        if (math[2][i % math[2].size()] == answers[i]) mCnt3++;
    }
    
    int sum = max(mCnt3, max(mCnt1, mCnt2));
    if (sum == mCnt1) answer.push_back(1);
    if (sum == mCnt2) answer.push_back(2);
    if (sum == mCnt3) answer.push_back(3);
    
    return answer;
}