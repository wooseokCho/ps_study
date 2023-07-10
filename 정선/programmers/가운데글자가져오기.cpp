#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int s_l = s.length();
    
    return s_l % 2 != 0? s.substr(s_l/2, 1) : s.substr(s_l/2-1, 2);   
}