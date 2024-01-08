// 개선후
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!=0)) return false;

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x%10;
            x/=10;
        }
        
        return x== revertedNumber || x == revertedNumber/10;

    }
};
// 개선전
class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers are all false
        if (x<0) return false;
        else if (x==0) return true;
        else { // x>0
            int digits = static_cast<int>(log10(x) + 1); // Calculate number of digits
            stack<int> stk;
            // even
            if(digits % 2 == 0) {
                for(int i = 0; i<digits/2; i++) {
                    stk.push(x%10);
                    x/=10;
                }
                for(int i = 0; i<digits/2; i++) {
                    if(stk.top() != x%10) return false;
                    x/=10;
                    stk.pop();
                }
                return true;
            }
            // odd
            else {
                for(int i = 0; i<digits/2; i++) {
                    stk.push(x%10);
                    x/=10;
                }
                x/=10;
                for(int i = 0; i<digits/2; i++) {
                    if(stk.top() != x%10) return false;
                    x/=10;
                    stk.pop();
                }
                return true;
            }
        }
    }
};