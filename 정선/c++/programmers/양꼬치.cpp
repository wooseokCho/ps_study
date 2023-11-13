#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    return 12000 * n + 2000 * k - 2000 * (n / 10);
}