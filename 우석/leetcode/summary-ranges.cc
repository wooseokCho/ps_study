class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        for(int i =0; i<nums.size();i++) {
            int s = nums[i];
            while(i+1<nums.size() && nums[i]+1 == nums[i+1]) {
                i++;
            }
            if(s==nums[i]) {
                ranges.push_back(to_string(s));
            }
            else{
                ranges.push_back(to_string(s)+"->" + to_string(nums[i]));
            }
        }
        return ranges;

    }
};