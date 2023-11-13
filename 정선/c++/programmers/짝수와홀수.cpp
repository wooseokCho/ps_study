#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    if (num % 2) {
        return "Odd";
    }
    return "Even";

    // 다른 풀이 bit 연산자 and를 사용해서 아래와 같이 쓸 수도 있음
    //  return num & 1 ? "Odd" : "Even";
}