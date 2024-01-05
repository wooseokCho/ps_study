#include <string>

using namespace std;

string s = "AEIOU";
int cnt = 0;

void dfs(string str, string& word, int* answer) {
    if (str == word) {
        *answer = cnt;
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        if (str.size() < 5) {
            cnt++;
            dfs(str + s[i], word, answer);
        }
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs("", word, &answer);
    
    return answer;
}