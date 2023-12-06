#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";
    int cnt = 0, zeroCnt = 0;
    
    while (s != "1") {
        sort(s.begin(), s.end());
        zeroCnt += s.find_first_of('1');
        int size = s.size() - s.find_first_of('1');
        s.clear();
        cnt++;
        
        while (size != 0) {
            s += to_string(size % 2);
            size /= 2;
        }
    }
   
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    
    return answer;
}