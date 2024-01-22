class Solution {
public:
    int getNextNumber(int n) {
        int sum = 0;
        while(n > 0) {
            int tmp = n%10;
            sum += tmp * tmp;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slowNumber = n;
        int fastNumber = n;

        do{
            slowNumber = getNextNumber(slowNumber);
            fastNumber = getNextNumber(getNextNumber(fastNumber));
        } while(fastNumber != 1 && slowNumber != fastNumber);

        return fastNumber == 1;
    }
};