class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> m;
    
        paragraph = regex_replace(paragraph, regex("[!|?|'|,|;|.]"), " ");
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        int maxCnt = 0;
        string word;
        stringstream ss(paragraph);
        
        while(ss >> word) {
            if(find(banned.begin(), banned.end(), word) != banned.end()) {
                continue;
            }
            m[word]++;
            maxCnt = max(maxCnt, m[word]);
        }
        
        string answer;

        for(auto kv : m) {
            if(kv.second == maxCnt) {
                answer = kv.first;
                break;
            }
        }

        return answer; 
    }
};