class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; 
        int len = nums.size();

        while(i < len) {
            if(nums[i] == val) {
                // swap
                nums[i] = nums[len-1];
                // reduce array size
                len--;
            }
            else {
                i++;
            }
        }

        return len;
    }
};