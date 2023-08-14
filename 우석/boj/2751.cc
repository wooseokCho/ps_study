#include <iostream>
#include <algorithm>

using namespace std;

int numArray[1000000+10];

int main(){

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> numArray[i];
    }

    sort(numArray, numArray+n);
    for(int i = 0; i<n; i++){
        cout << numArray[i] << '\n';
    }
    return 0;

}