#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector< vector<int> > threeSum(vector<int>& num)
    {
        vector< vector<int> > result;
        if(num.size() < 3) return result;
        sort(num.begin(), num.end());
        
        auto last = num.end();
        for (auto a = num.begin(); a < prev(last, 2); ++a) {
            auto b = next(a);
            auto c = prev(last);
            while(b < c)
            {
                if(*a + *b + *c < 0)
                {
                    ++b;
                }
                else if(*a + *b +*c > 0)
                {
                    --c;
                }
                else
                {
                    result.push_back({ *a, *b, *c });
                    ++b, --c;
                }

            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> num = {
        -1, 0 , 1, 2, -1, 4
    };
    
    vector< vector<int> > result = s.threeSum(num);

    for(auto i : result)
    {
        cout << "(";
        for(auto j : i) cout << j << " "; 
        cout << ")";
    }
    return 0;
}
