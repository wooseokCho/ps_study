class Solution {
public:
    string addBinary(string a, string b) {

        int lenA = a.length();
        int lenB = b.length();

        int tmp = 0;
        string retString = "";
        stack <char> retStack;
        for(int i = 0; i<min(lenA, lenB); i++){
            retStack.push((char)((a[lenA-1-i] + b[lenB-1-i] + tmp) % 2 + '0'));
            // update tmp
            tmp = (a[lenA-1-i]-'0' + b[lenB-1-i]-'0' + tmp) / 2;
        }

        // for left over, put it in
        if(lenA > lenB){
            for(int i = 0; i<lenA-lenB; i++){
                retStack.push((a[lenA-1 - lenB - i] + tmp) % 2 + '0');
                tmp = (a[lenA-1 - lenB - i] - '0' + tmp) / 2;
            }
        }
        if(lenB > lenA){
            for(int i = 0; i<lenB-lenA; i++){
                retStack.push((b[lenB-1 - lenA - i] + tmp) % 2 + '0');
                tmp = (b[lenB-1 - lenA - i] - '0' + tmp) / 2;
            }
        }
        // if tmp left
        if(tmp == 1) retStack.push('1');
        // build retString
        while(!retStack.empty()){
            retString += retStack.top(); retStack.pop();
        }
        return retString;
    }
};