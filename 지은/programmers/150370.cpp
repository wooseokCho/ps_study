#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;
    
    int tYear = stoi(today.substr(0, 4));
    int tMonth = stoi(today.substr(5, 2));
    int tDay = stoi(today.substr(8, 2));
    int todays = (tYear * 12 * 28) + (tMonth - 1) * 28 + tDay;
    
    for (int i = 0; i < terms.size(); i++) {
        m[terms[i].front()] = stoi(terms[i].substr(2, terms[i].size() - 2));
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        int limit_day = year * 12 * 28 + (month - 1) * 28 + day + (m[privacies[i].back()] * 28 - 1);
       
        if ( todays > limit_day )
            answer.push_back(i+1);
    }
    
    return answer;
}