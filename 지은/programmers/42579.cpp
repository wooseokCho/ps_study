#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp1(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool cmp2(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> m;
    unordered_map<string, vector<pair<int, int>>> m2;
    
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        m2[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp1);
    
    for(auto &x : m2){
        sort(x.second.begin(), x.second.end(), cmp2); 
    } 
    
     for(auto item : v){
        for(int j = 0; j < m2[item.first].size(); j++){
            answer.push_back(m2[item.first][j].second); 
            if (j) break;
        }
    }
    
    return answer;
}