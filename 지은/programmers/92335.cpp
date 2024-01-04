#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long num) {
    if (num < 2)
        return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = "";

    while (n != 0) {
        int num = n % k;
        str.push_back(num + '0');
        n /= k;
    }
    
    reverse(str.begin(), str.end());
    
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0' && index != i) {
            long long num = stoll(str.substr(index, i - index));
   
            index = i + 1;
            
            if (isPrime(num)) {
                answer++;
            }
        }
    }
    
    long long num = stoll(str.substr(index, str.size() - index));
    if (isPrime(num)) {
         answer++;
     }
    
    return answer;
}