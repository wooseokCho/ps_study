#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m;
    
    for (int i = 0; i < want.size(); i++) {
        m.insert({want[i], number[i]});
    }
    
    for (int i = 0; i <= discount.size() - 10; i++) {
        unordered_map<string, int> m_copy;

        for (int j = i; j < i + 10; j++) {
            m_copy[discount[j]]++;
        }
        
        if (m_copy == m)
            answer++;
    }
    
    return answer;
}