class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<bool> alphabet(26, false);
        vector<int> lastIdx(26, -1);
        string answer;

        for(int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(alphabet[s[i] - 'a']) {  // 중복된 문자
                continue;
            }
            
            while(!stk.empty() && s[i] < stk.top() && i < lastIdx[stk.top() - 'a']) {   // 사전식 순으로 정렬
                alphabet[stk.top() - 'a'] = false;
                stk.pop();
            }
            
            stk.push(s[i]);
            alphabet[s[i] - 'a'] = true;
        }

        while(!stk.empty()) {
            answer += stk.top();
            stk.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};