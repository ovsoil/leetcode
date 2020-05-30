class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        auto before1 = 2;
        auto before2 = 1;
        auto current = 0;
        for(auto i = 3; i <= n; ++i){
            current = before1 + before2;
            before2 = before1;
            before1 = current;
        }
        return   current;
        
    }
};
