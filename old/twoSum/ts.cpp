#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
        return vector<int>();
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
