class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;

        if(magazine.size() < ransomNote.size()) return false;

        for(int i = 0; i<magazine.size(); i++) {
            m[magazine[i]] += 1;
        }

        for(int i = 0; i<ransomNote.size(); i++) {
            if(m[ransomNote[i]] == 0) return false;
            m[ransomNote[i]]--;
        }
        return true;

    }
};

// 개선 전
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i = 0; i<magazine.size(); i++) {
            m1[magazine[i]] += 1;
        }

        for(int i = 0; i<ransomNote.size(); i++) {
            m2[ransomNote[i]] +=1;
        }

        for (auto& it: m2){
            if(m1[it.first] < it.second) return false;
        }
        return true;
    }
};