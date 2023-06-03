#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int i = 1; i < n; i++) { // 2부터 시작해도 됨..
        if (n % i == 1) {
            return i;
        }
    }
} 