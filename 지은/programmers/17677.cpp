#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    string tmp = "";
    
    for (int i = 0; i < str1.size() - 1; i++) {
        tmp = toupper(str1[i]);
        tmp += toupper(str1[i + 1]);
        
        v1.push_back(tmp);
    }
    
     for (int i = 0; i < str2.size() - 1; i++) {
        tmp = toupper(str2[i]);
        tmp += toupper(str2[i + 1]);
         
        v2.push_back(tmp);
    }
    
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (!isupper(v1[i][j])) {
                v1.erase(v1.begin() + i);
                i--;
                break;
            }
        }
    }
    
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (!isupper(v2[i][j])) {
                v2.erase(v2.begin() + i);
                i--;
                break;
            }
        }
    }
    
    double count = 0;
    double allCount = v1.size() + v2.size();
    
    if (allCount == 0) {
        return 65536;
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int size = (v1.size() < v2.size()) ? v1.size() : v2.size();
 
    for (int i = 0; i < v1.size(); i++) {
        auto it = find(v2.begin(), v2.end(), v1[i]);
        if (it != v2.end()) {
            count++;
            v2.erase(it);
        }
    }
    
    allCount -= count;
    
    answer = (count / allCount) * 65536;
    
    return answer;
}