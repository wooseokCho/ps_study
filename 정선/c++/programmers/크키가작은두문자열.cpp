#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for (int i=0; i<t.size()-p.size()+1; i++) {
        string part = t.substr(i, p.size());
        
        if (part <= p) {
            answer += 1;
        }
    }
    return answer;
}