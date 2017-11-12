/*
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int trap(vector<int> &num){
        int result = 0;
        int n = num.size();
        vector<int> max_left(n, 0), max_right(n, 0);
        
        for (int i = 1; i < n-1; ++i) {
            max_left[i] = max(max_left[i - 1], num[i - 1]);
            max_right[n- 1 - i] = max(max_right[n - i], num[n - i]);
        }

        for(int i = 1; i < n-1; ++i){
            int height = min(max_left[i], max_right[i]);
            if(height > num[i]){
                result += height - num[i];
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> num = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(num) << endl;
    return 0;
}
