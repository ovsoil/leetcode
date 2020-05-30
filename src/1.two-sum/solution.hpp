class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(auto i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if(map.find(complement) == map.end())
                map[nums[i]] = i;
            else
                return {map[complement], i};
        }
        return {};
    }
};
