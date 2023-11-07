#include <iostream>

using namespace std;

void print_solution(int a, int b, int k){
    cout << "Case #" << k << ": " << a << " + " << b << " = " << a+b << '\n';
}

int main(){
    int n;
    int a, b;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a >> b;
        print_solution(a, b, i+1);
    }
    return 0;
}