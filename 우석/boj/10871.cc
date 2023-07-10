#include <iostream>

using namespace std;

int main(){
    int N, X, k;
    cin >> N >> X;
    for(int i = 0; i<N; i++){
        cin >> k;
        if(k < X) cout << k << ' ';
    }
    cout << endl;
    return 0;
}