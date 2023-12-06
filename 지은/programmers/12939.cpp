#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<int> num;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            num.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    if (!tmp.empty())
        num.push_back(stoi(tmp));
    
    sort(num.begin(), num.end());
    
    answer = to_string(num.front()) + " " + to_string(num.back());
    
    return answer;
}