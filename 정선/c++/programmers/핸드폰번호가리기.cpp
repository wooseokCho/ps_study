#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int length = phone_number.length();
    
    // for (int i=0; i<length-4; i++) {
    //     // cout<<phone_number<<" "<<length<<endl;
    //     phone_number.replace(i, 1, "*");
    // }
    
    // 처음에 아래처럼 했는데 왜 안되지? -> 되는데? 뭘 실수한거지? vector처럼 문자 대체할 수 있다~
    for (int i = 0; i < phone_number.size() - 4; i++ )
    {
        phone_number[i] = '*';
    }

    return phone_number;
}