#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer = {x};
    
    for (int i=2; i <= n; i++) {
        answer.push_back(x*i); 
    }

    return answer;


    // 그냥 answer[i]처럼 인덱싱해도 됨
    // 단 이때 answer vector 크기 정의 필요
    // vector<long long> answer(n, x); // vector.assign(범위, 초기값) : 범위만큼 초기값으로 초기화

    // for (int i = 1; i < n; i++)
    //     answer[i] = answer[i - 1] + x;

}