#include <string>
#include <vector>
#include <algorithm>
// 대문자는 65 ~ 90까지 소문자는 97 ~ 122번까지
using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<int>());
    return s;
}