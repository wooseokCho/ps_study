#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    vector<string> history;
    
    for (int i = 1; i < words.size(); i++) {
        history.push_back(words[i - 1]);
       
        if (words[i].front() != words[i - 1].back() || find(history.begin(), history.end(), words[i]) != history.end()) {
            answer[0] = (i + 1) % n ? (i + 1) % n : n;
            answer[1] = (i / n) + 1;
            
            return answer;
        }
    }

    return answer;
}