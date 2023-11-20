#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1. 오늘 날짜를 일수로 변환
    int t_year = stoi(today.substr(0, 4));
    int t_month = stoi(today.substr(5, 2));
    int t_day = stoi(today.substr(8, 2));
    int today_date = t_day + t_month * 28 + t_year * 28 * 12;
    
    // 2. 약관 정보에서 달 수를 일 수로 변경후 map에 저장
    map<char, int> info;
    for(auto term : terms) {
        char type = term[0];
        int day = stoi(term.substr(2)) * 28;
        info[type] = day;
    }
    
    // 3. 계약 시작 날짜 + 계약일수 - 1 v.s 오늘 날짜
    for(int i = 0; i < privacies.size(); i++) {
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        char type = privacies[i][11];
        
        int start_date = day + month * 28 + year * 28 * 12;
        int end_date = start_date + info[type] - 1;
        
        if(end_date < today_date) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}