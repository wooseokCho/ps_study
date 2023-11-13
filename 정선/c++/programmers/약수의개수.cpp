#include <string>
#include <vector>

using namespace std;

int count_divisor(int x) {
    int divisor_n = 1;
    for (int i=2; i < x+1; i++) {
        if (x % i == 0) {
            divisor_n += 1;
        }
    }
    return divisor_n;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i=left; i <=right; i++) {
        if (count_divisor(i) % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    
    return answer;
}