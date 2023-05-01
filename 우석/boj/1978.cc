#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool isPrimeArray[1000+10];

void fillIsPrimeArray(){
    // initialize
    fill(isPrimeArray, isPrimeArray+1000+10, true);

    isPrimeArray[1] = false;

    // 에라토스테네스의 체
    for(int i = 2; i<=1000; i++){
        if(isPrimeArray[i]){
            for(int j = 2*i; j<=1000; j+=i){
                isPrimeArray[j] = false;
            }
        }
    }

}

int main(){

    cin >> N;
    vector<int> v(N);
    for(int i = 0; i<N; i++){
        cin >> v[i];
    }

    fillIsPrimeArray();
    int cnt = 0;
    for(int i = 0; i<N; i++){
        if(isPrimeArray[v[i]]) cnt++;
    }

    cout << cnt << endl;
    return 0;
}