#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int count = goal.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (count != 0) {
        count--;
        
        if (cards1[i] == goal[0]) {
            cards1.erase(cards1.begin() + i);
            goal.erase(goal.begin());
            continue;
        }
        if (cards2[j] == goal[k]) {
            cards2.erase(cards2.begin() + j);
            goal.erase(goal.begin());
            continue;
        }
    }
    
    if (goal.empty()) answer = "Yes";
    else answer = "No";
    
    return answer;
}