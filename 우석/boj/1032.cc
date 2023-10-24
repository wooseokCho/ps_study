#include <iostream>
#include <string>
#include <map>

using namespace std;

string stringArr[50+5];
char returnString[50+5];
int n;

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> stringArr[i];
    }

    int stringLen = stringArr[0].length();
    map<int, char> myMap;

    // for first element
    for(int i = 0; i<stringLen; i++){
        myMap.insert({i,stringArr[0][i]});
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<stringLen; j++){
            if(myMap[j] != stringArr[i][j]){
                myMap.erase(j);
            }
        }
    }

    for(int i = 0; i<stringLen; i++){
        if(myMap[i]){
            returnString[i] = myMap[i];
        }
        else{
            returnString[i] = '?';
        }
    }
    cout << returnString << endl;
    return 0;
}