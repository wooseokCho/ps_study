class Solution {
public:
    char stk[10000+10];
    int sp = 0;

    void push(char k) {
        stk[++sp] = k;
    }
    char top() {
        return stk[sp];
    }
    void pop() {
        sp--; 
    }
    bool empty(){
        return (sp==0) ? true : false;
    }

    bool isValid(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') push(s[i]);
            else if ((s[i] == ')' && top() == '(') || 
            (s[i] == ']' && top() == '[') || (s[i] == '}' && top() == '{')){
                pop();
            }
            else return false;
        }
        return empty();
    }
};