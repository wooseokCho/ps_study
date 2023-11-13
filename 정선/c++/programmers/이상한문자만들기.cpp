#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool odd_flag = true;
    
    for (int i=0; i < s.size(); i++) {
        if (s[i] == ' ') {
            odd_flag = true;
            continue;
        }
        else if (odd_flag) {
            s[i] = toupper(s[i]);
        }
        else {
            s[i] = tolower(s[i]);
        }
        odd_flag = !odd_flag;
    }
    
    return s;
}