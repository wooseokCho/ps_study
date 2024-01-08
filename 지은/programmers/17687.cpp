#include <string>
#include <vector>

using namespace std;

string s = "0123456789ABCDEF";

string invertNum(int n, int num) {
    string str = "";
    if (num == 0)
        return "0";
    
    while (num) {
        str = s[num % n] + str;
        num /= n;
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    string res = "";
    
    while (res.size() <= m * t) {
        res += invertNum(n, num++);
    }
    
    int index = p - 1;
    while (answer.size() < t) {
        answer.push_back(res[index]);
        index += m;
    }
    
    return answer;
}