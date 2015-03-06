#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class solution
{
public:
    int longestConsecutiveSequence(const vector<int> &nums)
    {
        unordered_map<int, bool> used;
        for(auto i : nums) used[i] = false;
        int length = 1;

        for(auto i : nums)
        {
            if(used[i]) continue;

            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }

            for(int j = i - 1; used.find(j) != used.end(); --j){
                used[j] = true;
                ++length;
            }
        }
        return length;
    }
};

int main(int argc, const char *argv[])
{
    int num[7] = {
        100, 4, 200, 1, 4, 3, 2
    };
    vector<int> vec;
    for(auto i : num) vec.push_back(i);

    for(auto i : vec) cout << i << " ";
    cout << endl;
    solution s;

    cout << s.longestConsecutiveSequence(vec) << endl;
    
    return 0;
}
