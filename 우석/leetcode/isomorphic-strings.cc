class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1;
        map<char, char> m2;
        char c1, c2;

        for (int i = 0; i < s.length(); i++) {
            c1 = s[i]; c2 = t[i];
            if (m1.contains(c1) && m1.find(c1)->second != c2) {
                return false;
            }
            else if (m2.contains(c2) && m2.find(c2)->second != c1) {
                return false;
            }
            else {
                m1.insert({c1, c2}); m2.insert({c2, c1});
            }
        }
        return true;
    }
};
