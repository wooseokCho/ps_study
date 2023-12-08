#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> stk;
    
    if (s.empty() || s.size() % 2 != 0)
        return answer;
    
    for (int i = 0; i < s.size(); i++) {
        if (!stk.empty() && s[i] == stk.top()) {
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    
    answer = stk.empty() ? 1 : 0;    

    return answer;
}