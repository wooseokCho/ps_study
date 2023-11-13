#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n >= 10) {
        answer += n % 10;
        n /= 10;
    }
    answer += n;
    
    return answer;
}