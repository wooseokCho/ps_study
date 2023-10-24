#include <iostream>

using namespace std;

int chessPieces[7];
int defaultChessPieces[] = {1,1,2,2,2,8};

int main(){
    int tmp;
    for(int i = 0; i<6; i++){
        cin >> tmp;
        chessPieces[i] = defaultChessPieces[i]-tmp;
    }
    for(int i = 0; i<6; i++){
        cout << chessPieces[i] << ' ';
    }
    cout << '\n';
    return 0;

}