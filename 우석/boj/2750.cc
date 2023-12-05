#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int intArray[1000+10];
    cin >> N;

    for(int i = 0 ; i<N; i++){
        cin >> intArray[i];
    }
    sort(intArray, intArray+N);

    for(int i = 0; i<N; i++){
        cout << intArray[i] << '\n';
    }
    return 0;
}