#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b; // 내림차순 정렬을 위해 '>' 연산자 사용
}

long long solution(long long n) {
    string n_str = to_string(n);

    sort(n_str.begin(), n_str.end(), compare);
    
    long long answer = stoll(n_str);
    
    return answer;
}

// compare 함수 대신 greater<char>() 사용할 수 있음