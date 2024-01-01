#include <bits/stdc++.h>
using namespace std;

struct Song {
    int idx;
    int plays;
    
    bool operator<(const Song &other) const {
        if (plays == other.plays) {
            return idx < other.idx;
        }
        return plays > other.plays;
    }
};

struct Genre {
    string name;
    int totalPlays;
};

struct Compare {
    bool operator()(const Genre &a, const Genre &b) {
        return a.totalPlays < b.totalPlays;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m; // {장르, 재생횟수의 합}
    map<string, vector<Song>> mm; // MultiMap {고유번호, 재생횟수}
    
    for(int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        mm[genres[i]].push_back({i, plays[i]});
    }
    
    priority_queue<Genre, vector<Genre>, Compare> pq;
    
    for(auto entry : m) {
        pq.push({entry.first, entry.second});
    }
    
    while(!pq.empty()) {
        string genre = pq.top().name;
        pq.pop();
        
        sort(mm[genre].begin(), mm[genre].end());
        
        answer.push_back(mm[genre][0].idx);
        
        if(mm[genre].size() >= 2) {
            answer.push_back(mm[genre][1].idx);
        }
    }
    
    return answer;
}