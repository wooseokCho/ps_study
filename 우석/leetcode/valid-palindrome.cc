class Solution {
public:
    bool isPalindrome(string s) {
        int ptr1 = 0;
        int ptr2 = s.length()-1;

        while(ptr2>ptr1) {
            // move to alphabet
            while(!isalnum(s[ptr1]) && ptr1 < s.length()-1) ptr1++;
            while(!isalnum(s[ptr2]) && ptr2 > 0) ptr2--;

            if(ptr1 >= ptr2) return true;
            else {
                if(s[ptr1] == s[ptr2] || 
                (isalpha(s[ptr1]) && isalpha(s[ptr2]) && (abs(s[ptr1] - s[ptr2]) == 32))) {
                    ptr1++; ptr2--;
                }
                else return false;
            }
        }
        return true;
    }
};