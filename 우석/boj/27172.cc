#include <iostream>

using namespace std;

bool cardArray[1'000'000 + 10];
int peopleCard[100'000 + 10];
int returnVal[1'000'000 + 10];
int n, inputNum;

void check(int num) {
    for (int i = num; i <= 1'000'000; i+=num) {
        if(cardArray[i]) {
            returnVal[num]++;
            returnVal[i]--;
        }
    }
    return;
}

int main(){
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> inputNum;
        cardArray[inputNum] = true;
        peopleCard[i] = inputNum;
    }

    for(int i = 0; i<n; i++) {
        check(peopleCard[i]);
    }

    for(int i = 0; i<n; i++) {
        cout << returnVal[peopleCard[i]] << ' ';
    }
    cout << endl;
    return 0;
}