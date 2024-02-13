class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 0; //carry 

        for(int i = digits.size()-1 ; i>=0; i--) {
            if(i == digits.size()-1) digits[i] += (flag + 1);
            else digits[i] += flag;
            if(digits[i] >= 10) {
                digits[i] = 0;
                flag = 1;
            }
            else {
                flag = 0;
                return digits;
            }
        }
        if(flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};