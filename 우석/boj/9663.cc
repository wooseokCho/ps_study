#include <iostream>

using namespace std;
int N;
int ans;

bool board[15][15];
bool colCheck[15];
bool crossCheck1[30];
bool crossCheck2[30];

bool available(int row, int col){
    return !(colCheck[col] || crossCheck1[row+col] || crossCheck2[col-row+(N-1)]);
}

void cal(int row){
    if(row == N){
        ans += 1;
        return;
    }
    for(int col= 0; col < N; col++){
        if(available(row, col)){
            board[row][col] = true;
            // col
            colCheck[col] = true;
            // cross 1
            crossCheck1[row+col] = true;
            // cross 2
            crossCheck2[col-row+(N-1)] = true;
            cal(row+1);
            board[row][col] = false;
            // col
            colCheck[col] = false;
            // cross 1
            crossCheck1[row+col] = false;
            // cross 2
            crossCheck2[col-row+(N-1)] = false;
        }
    }
}


int main(){
    cin >> N;
    cal(0);
    cout << ans << endl;
    return 0;
}