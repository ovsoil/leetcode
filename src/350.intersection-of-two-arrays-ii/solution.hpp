class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> sets;
        for (auto x: nums1) sets[x]++;
        vector<int> result;
        for (auto x: nums2) {
            auto it = sets.find(x);
            if (it != sets.end() && --it->second >= 0) {
                result.push_back(x);
            }
        }
        return result;
    }


    // 对于有序数组
    vector<int> intersect_sorted(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        int i = 0, j = 0;
        int k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] == nums2[j])
            {
                nums2[k] = nums1[i];
                i++, j++, k++;
            }
        }
        return vector<int>(nums2.begin(), nums2.begin() + k);
    }
};
