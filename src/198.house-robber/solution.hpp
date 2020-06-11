class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        int r1 = nums[0];
        int r2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int tmp = r2;
            r2 = max(nums[i] + r1, r2);
            r1 = tmp;
        }
        return r2;
    }
};
