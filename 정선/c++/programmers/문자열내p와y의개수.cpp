#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt = 0;
    
    for (int i=0; i < s.length(); i++) {
        if (s[i] == 'p' or s[i] == 'P') {
            cnt += 1;
        }
        if (s[i] == 'y' or s[i] == 'Y') {
            cnt -= 1;
        }
    }

    return (cnt == 0) ? true : false;
}