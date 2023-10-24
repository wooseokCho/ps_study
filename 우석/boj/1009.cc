#include <iostream>

using namespace std;

int solve(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a%10;

    int p = solve(a,b/2);
    int q = b%2;

    if(q == 0){
        return (p*p)%10;
    }
    else{
        return (p*p*a)%10;
    }
}

int main(){
    int t;
    cin >> t;
    
    int a, b;
    for(int i = 0; i<t; i++){
        cin >> a >> b;
        int sol = solve(a,b);
        sol = (sol == 0) ? 10:sol;
        cout << sol << '\n';
    }
    return 0;
}