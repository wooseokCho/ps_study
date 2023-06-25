#include <string>
#include <iostream>

using namespace std;

bool solution(int x) {
    int digit_sum = 0;
    string x_str = to_string(x);
    
    for (int i=0; i < x_str.size() ; i++) {
        digit_sum += x_str[i] - '0';
    }
    
    if (x % digit_sum == 0) {
        return true;
    }
    else {
        return false;
    }
}

// 굳이 string 안하고 int type tmp 추가해서 할 수 있음
// if문도 위 처럼 말고 return x % nSum == 0 ? true : false;과 같이 쓸 수 있음