class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // size k set 
        set<int> windowSet;
        for (int i = 0; i < nums.size(); i++) {
            if(windowSet.contains(nums[i])) return true;
            windowSet.insert(nums[i]);
            if(windowSet.size() > k) {
                windowSet.erase(nums[i-k]);
            }
        }
        return false;
    }
};