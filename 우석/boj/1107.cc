#include <iostream>
#include <cmath>

using namespace std;

int toMove, M;
bool button[10+2];
int minCnt = 987654321;

int abs(int a){
    return (a>0) ? a : -a;
}

bool available(){
    for(int i = 0; i<=9; i++){
        if(button[i]) return true;
    }
    return false;
}

void findCnt(int step, int curNum){ // dfs
    if(step == 7){
        return;
    }
    if(step != 0) minCnt = min(minCnt, step + abs(curNum-toMove));
    for(int i = 0; i<=9; i++){
        if(!button[i]) continue;
        curNum += i * pow(10, step); 
        findCnt(step+1, curNum);
        curNum -= i * pow(10, step);
    }
}

int main(){
    cin >> toMove >> M;
    
    for(int i = 0; i<10; i++){
        button[i] = true;
    }
    for (int i = 0; i<M; i++){
        int k;
        cin >> k; 
        button[k] = false;
    }

    // just move using ++ --
    minCnt = min(minCnt, abs(100-toMove));

    // move and use ++ --
    // move to closest one
    // if all buttons are not available, skip
    if(available()){
        findCnt(0, 0);
    }

    cout << minCnt << endl;

    return 0;

}