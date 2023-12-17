#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    vector<int> v;

    for (int t : tangerine) {
        m[t]++;
    }
    
    for (auto elem: m) {
        v.push_back(elem.second);
    }
    
    sort(v.begin(), v.end());

    int cnt = tangerine.size();
    int answer = v.size();
    
    for (int i = 0; i < v.size(); i++) {
        if (cnt - v[i] < k) break;
        cnt -= v[i];
        answer--;
    }
    
    return answer;
}