#include <iostream>

using namespace std;

int main(){
    int H, M;
    cin >> H >> M;

    int newM = (M-45<0) ? M+15 : M-45; 
    int newH = (M-45<0) ? H-1 : H;
    newH = (newH<0) ? newH+24 : newH;
    cout << newH << ' ' << newM << endl;
}