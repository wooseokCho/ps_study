#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> v(10, 0);
    vector<char> res;
    
    for(int i = 0; i < X.size(); i++) 
        v[X[i] - '0']++;
    for(int i = 0; i < Y.size(); i++) 
        if(--v[Y[i] - '0'] >= 0) res.push_back(Y[i]);
    
    sort(res.begin(), res.end(), greater<char>());
    
    for(auto c : res) answer.push_back(c);
    
    if (answer.empty()) return "-1";
    if (answer[0] == '0') return "0";
    
    return answer;
}