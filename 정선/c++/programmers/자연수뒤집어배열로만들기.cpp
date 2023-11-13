#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string n_str = to_string(n);

    for (int i = n_str.length(); i > 0; i--){ 
        answer.push_back(n_str[i-1] - '0'); 
    }

    return answer;
}

// 다른 풀이
// 굳이 형변환 하는 것보다 나머지 연산 사용해서 바로 추가할 수도 있음
