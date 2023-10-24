#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        } else {
            if (stk.empty() || stk.top() != '(') {
                answer = false;
                return answer;
            } else {
                stk.pop();
            }
        }
    }
    answer = (stk.empty()) ? true : false;
    
    return answer;
}