#include <iostream>
#include <string>

using namespace std;

string s;

int main(){
    cin >> s;

    for(int i = 0; i<s.length(); i++){
        if(s[i]>='a') s[i] = s[i]-'a'+'A';
        else s[i] = s[i] - 'A' + 'a';
    }

    cout << s << endl;
    return 0;
}