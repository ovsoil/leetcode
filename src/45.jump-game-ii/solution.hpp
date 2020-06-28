class Solution {
private:
    unordered_map<int, int> cache;
    int jumpInter(vector<int>& nums, int start) {
        if (start == nums.size() - 1) return 0;
        if (cache.count(start)) return cache[start];
        int n = min(int(nums.size()) - start - 1, nums[start]);
        int minJ = INT_MAX - 1;
        for (int i = 1; i <= n; ++i) {
            int j = jumpInter(nums, start + i);
            if (j < minJ) minJ = j;
        }
        cache[start] = minJ + 1;
        return minJ + 1;
    }
public:
    int jump0(vector<int>& nums) {
        return jumpInter(nums, 0);
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int step = 0, farest = 0, nextFarest = nums[0];
        for (int i = 0; i < n - 1; ++i) {
            farest = max(farest, i + nums[i]);
            if (i == nextFarest) {
                nextFarest = farest;
                ++step;
            }
        }
        return step + 1;
    }
};
