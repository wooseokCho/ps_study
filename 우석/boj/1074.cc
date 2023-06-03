#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int N, r, c;

int main(){
    cin >> N >> r >> c;

    // calculate section and put it into stack
    stack<int> sectionStack;

    for(int i = N; i>=1; i--){
        int div = pow(2, i-1);
        int q1 = r/div;
        int q2 = c/div;

        int r1 = r%div;
        int r2 = c%div;

        sectionStack.push(q1*2+q2);
        r = r1;
        c = r2;
    }

    // calculate number
    int mul = 1;
    int num = 0;
    while(!sectionStack.empty()){
        int curVal = sectionStack.top(); sectionStack.pop();
        num += curVal*mul;
        mul *= 4;
    }
    
    cout << num << endl;
    return 0;
}