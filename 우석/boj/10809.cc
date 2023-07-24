#include <iostream>
#include <cstring>

using namespace std;

int alphabetArray[26];
string s;

int main(){
    // initialize 
    for(int i = 0; i<26; i++){
        alphabetArray[i] = -1;
    }

    cin >> s;
    int curIndex = 0;
    for(int i = 0; i<s.length(); i++){
        curIndex = s[i]-'a';
        if(alphabetArray[curIndex] == -1){
            alphabetArray[curIndex] = i;
        }
    }

    for(int i = 0; i<26; i++){
        cout << alphabetArray[i] << ' ';
    }
    cout << endl;
    return 0;
}