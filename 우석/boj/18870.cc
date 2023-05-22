#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int originalIntArray[1000000+10];
int totalInt;

int main(){
    cin >> totalInt;

    for(int i = 0; i<totalInt; i++){
        cin >> originalIntArray[i];
    }

    // remove duplicate by set
    set<int> intSet(originalIntArray, originalIntArray+totalInt);
    // set to vector
    vector<int> intVector(intSet.begin(), intSet.end());

    // sort vector
    sort(intVector.begin(), intVector.end());

    for(int i = 0; i<totalInt; i++){
        cout << lower_bound(intVector.begin(), intVector.end(), originalIntArray[i]) - intVector.begin() <<' ';
    }
    cout << '\n';

    return 0;


}