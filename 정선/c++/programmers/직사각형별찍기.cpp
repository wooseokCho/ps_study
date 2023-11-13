#include <iostream>

using namespace std;

int main(void) {
    int n;
    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}