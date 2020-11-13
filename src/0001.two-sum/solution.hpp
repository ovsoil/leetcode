class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sub;
        for (int i = 0; i < nums.size(); ++i) {
            int part = target - nums[i];
            if (!sub.count(part))
                sub[nums[i]] = i;
            else
                return vector<int> {sub[part], i};
        }
        return vector<int>();
    }
};
