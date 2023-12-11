class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> bracket = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if(stk.empty()) {
                    return false;
                }

                if(stk.top() == bracket[c]) {
                    stk.pop();
                } else return false;
            }
        }

        return stk.empty();
    }
};