#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size() != 4 and s.size() != 6) {
        return false;
    }
    
    for (int i=0; i< s.size(); i++) {
        if (s[i] < '0' or s[i] > '9') { // 혹은 (!isdigit(s[i])) 사용 가능
            return false;
        }
    }
    return true;
}