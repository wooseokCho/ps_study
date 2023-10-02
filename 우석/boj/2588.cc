#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int ans = 0;
    int tmp;
    int numToMultiply = 1;
    for(int i = 0; i<3; i++){
        tmp = n*(m%10);
        cout << tmp << '\n';
        // logic
        m = m/10;
        ans += tmp*numToMultiply;
        numToMultiply*=10;
    }
    cout << ans << '\n';
    return 0;
}