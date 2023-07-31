#include <iostream>
#include <algorithm>

using namespace std;

int w[3];
int main(){
    for(int i = 0; i<3; i++){
        cin >> w[i];
    }
    sort(w,w+3);
    cout << w[1] << endl;
    return 0;
}