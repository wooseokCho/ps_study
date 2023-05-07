#include <iostream>

using namespace std;

int N;

int main(){
    cin >> N;

    for(int i = 1; i<=9; i++){
        cout << N << " * " << i << " = " << N*i << endl;
    }

    return 0;
}