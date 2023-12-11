#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> m1;
    map<string, int> m2;
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for (auto id: id_list) {
        m1[id] = 0;
        m2[id] = 0;
    }
    
    for (int i = 0; i < report.size(); i++) {
        string p = report[i].substr(report[i].find_first_of(" ") + 1);
        m1[p]++;
    }
    
    for (int i = 0; i < report.size(); i++) {
        string p1 = report[i].substr(0, report[i].find_first_of(" "));
        string p2 = report[i].substr(report[i].find_first_of(" ") + 1);
        
        if (m1[p2] >= k)
            m2[p1]++;
    }
    
    for (auto id: id_list)
        answer.push_back(m2[id]);
    
    return answer;
}