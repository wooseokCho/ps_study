#include <iostream>
#include <algorithm>

using namespace std;

int height[10];

int main(){
    int totalHeightSum = 0;

    for(int i = 0; i<9;i++){
        cin >> height[i];
        totalHeightSum += height[i];
    }

    sort(height, height+9);

    int i, j;
    int breakFlag = 0;
    for(i = 0; i<9;i++){
        for(j = i+1; j<9; j++){
            if(totalHeightSum - height[i] - height[j] == 100){
                breakFlag = 1;
                break;
            }
        }
        if(breakFlag) break;
    }
    
    for(int k = 0; k<9; k++){
        if(k==i || k==j) continue;
        cout << height[k] << endl;
    }

    return 0;
}