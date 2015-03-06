#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (mapping.find(nums[i]) == mapping.end())
            {
                mapping[target - nums[i]] = i;
            }
            else
            {
                result.push_back(mapping[nums[i]] + 1);
                result.push_back(i + 1);
                return result;
            }
        }
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> nums = {
        2, 7, 11 ,15
    };
    int target = 17;

    vector<int> out = s.twoSum(nums, target);
    for(auto i : out) cout << i << " ";
    cout << endl;
    return 0;
}
