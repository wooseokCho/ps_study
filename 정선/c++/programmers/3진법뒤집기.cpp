#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> n_3;
    
    while (n!=1) {
        n_3.push_back(n % 3);
        n /= 3;
    }
    n_3.push_back(n % 3);
    
    int m = 1;
    
    for (int i=n_3.size()-1; i>=0; i--) {
        // cout<<n_3[i]<<" "<<m<<endl;
        answer += (n_3[i] * m);
        m *= 3;
    }
    
    return answer;
}