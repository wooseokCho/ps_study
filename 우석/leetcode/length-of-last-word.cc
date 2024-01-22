class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0; int flag = 0;
        for(int i = s.length()-1; i>=0; i--) {
            if(s[i] == ' ' && flag == 0) {
                continue;
            }
            else if(s[i] == ' ' && flag == 1) return counter;
            else {
                flag = 1;
                counter ++;
            }
        }
        return counter;
    }
};