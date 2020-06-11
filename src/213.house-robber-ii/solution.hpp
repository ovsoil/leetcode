class Solution {
private:
    int robIn(vector<int>& nums, int begin, int end) {
        if (begin >= end) return 0;
        if (begin == end - 1) return nums[begin];
        int r1 = nums[begin];
        int r2 = max(nums[begin], nums[begin + 1]);
        for (int i = begin + 2; i < end; ++i) {
            int tmp = r2;
            r2 = max(nums[i] + r1, r2);
            r1 = tmp;
        }
        return r2;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robIn(nums, 1, n), robIn(nums, 0, n - 1));
    }
};
