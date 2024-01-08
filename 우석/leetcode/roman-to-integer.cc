class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;

        for(int i = 0; i<s.length(); i++) {
            if(s[i] == 'I') {
                // check if IV IX 
                if(s[i+1] == 'V'){
                    ret+=4;
                    i++;
                    continue;
                }
                else if (s[i+1] == 'X') {
                    ret+=9;
                    i++;
                    continue;
                }
                else ret+=1;
            }

            if(s[i] == 'X') {
                // check if XL XC 
                if(s[i+1] == 'L'){
                    ret+=40;
                    i++;
                    continue;
                }
                else if (s[i+1] == 'C') {
                    ret+=90;
                    i++;
                    continue;
                }
                else ret+=10;
            }

            if(s[i] == 'C') {
                // check if CD CM 
                if(s[i+1] == 'D'){
                    ret+=400;
                    i++;
                    continue;
                }
                else if (s[i+1] == 'M') {
                    ret+=900;
                    i++;
                    continue;
                }
                else ret+=100;
            }
            if(s[i] == 'V') ret+= 5;
            if(s[i] == 'L') ret+= 50;
            if(s[i] == 'D') ret+= 500;
            if(s[i] == 'M') ret+= 1000;
        }
        return ret;
    }
};