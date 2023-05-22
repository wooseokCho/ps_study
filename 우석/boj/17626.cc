#include <iostream>

using namespace std;

int toMake;
int dpTable[50000+10];

int main(){
    cin >> toMake;

    // build dpTable
    for(int i = 1; i<=50000; i++){
        int tmpMin = 987654321;    
        int toSubtract = 1;
        while(i - toSubtract*toSubtract>=0){
            tmpMin = min(tmpMin, dpTable[i - toSubtract*toSubtract]+1);
            toSubtract++;
        }
        dpTable[i] = tmpMin;
    }
    cout << dpTable[toMake] << '\n';
    return 0;
}