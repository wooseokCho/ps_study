class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {    // i : Palindrome의 가운데 문자
            int left = i, right = i, len;   // 홀수 Palindrome
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int oddLen = right - left - 1;

            left = i, right = i + 1;   // 짝수 Palindrome
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int evenLen = right - left - 1;

            len = max(oddLen, evenLen);

            if (maxLen < len) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }
};