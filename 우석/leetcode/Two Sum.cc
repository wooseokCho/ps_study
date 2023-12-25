class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueIndexMap;
        vector<int> returnVector;

        for(int i = 0; i<nums.size(); i++) {
            int diff = target - nums[i];
            auto j = valueIndexMap.find(diff);
            if(j == valueIndexMap.end()){
                valueIndexMap.insert(make_pair(nums[i], i));
                continue;
            }
            returnVector.push_back(i);
            returnVector.push_back(j->second);
        }
        return returnVector;
    }
};