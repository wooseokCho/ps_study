class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;

		while (i < j) {
			if (!isalpha(s[i]) && !isdigit(s[i])) {
				i++;
			}
			else if (!isalpha(s[j]) && !isdigit(s[j])) {
				j--;
			}
			else {
				if (tolower(s[i]) != tolower(s[j])) {
					return false;
				}
				i++;
				j--;
			}
		}

		return true;
	}
};