#include <iostream>

using namespace std;

int A, B, V;

int main(){
    cin >> A >> B >> V;
    
    int day = (V-A) / (A-B);
    day += ((V-A)%(A-B) == 0) ? 0 : 1;
    day ++;
    cout << day << endl;
    return 0;
}