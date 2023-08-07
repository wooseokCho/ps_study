#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.compare("A+") == 0) cout << 4.3 << endl;
    else if(s.compare("A0") == 0) cout << "4.0" << endl;
    else if(s.compare("A-") == 0) cout << 3.7 << endl;
    else if(s.compare("B+") == 0) cout << 3.3 << endl;
    else if(s.compare("B0") == 0) cout << "3.0" << endl;
    else if(s.compare("B-") == 0) cout << 2.7 << endl;
    else if(s.compare("C+") == 0) cout << 2.3 << endl;
    else if(s.compare("C0") == 0) cout << "2.0" << endl;
    else if(s.compare("C-") == 0) cout << 1.7 << endl;
    else if(s.compare("D+") == 0) cout << 1.3 << endl;
    else if(s.compare("D0") == 0) cout << "1.0" << endl;
    else if(s.compare("D-") == 0) cout << 0.7 << endl;
    else if(s.compare("F") == 0) cout << "0.0" << endl;

    return 0;
}
