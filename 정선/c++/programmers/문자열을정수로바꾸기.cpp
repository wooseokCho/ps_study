#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool minus = false;
    
    if (s[0] == '-') {
        s = s.substr(1, s.size());
        minus = true;
    }
    if (s[0] == '+') {
        s = s.substr(1, s.size());
    }
    
    for (int i=s.size()-1; i >= 0; i--) {
        answer += (s[i] - '0') * pow(10, s.size()-(i+1));
    }
    
    if (minus) {
        answer -= answer * 2;
    }
    
    return answer;
}
// stoi 함수 사용
// '0', '9' 범위 이용해서 pow 안 쓰고도 할 수 있음