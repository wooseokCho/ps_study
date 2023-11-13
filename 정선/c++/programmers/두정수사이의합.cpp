#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long al = a;
    long long bl = b;
    
    if (a == b) {
        return a;
    }
    
    if (a > b) {
        bl = a;
        al = b;
    }
    
    answer = (al + bl) * ((bl - al + 1) / 2);
    
    if (((bl - al + 1) % 2) == 1) {
        answer += al + (bl - al + 1) / 2;
    }

    // a,b 미리 형변환 안 해주면... int로 바뀌어서 범위 오류 때문에 문제가 안풀린겨

    return answer;
}