# My leetcode practice with a unit test framework

:sweat_drops:　Write leetcode code and test them easily with full unit test features!　:sweat_drops:

## Example

- Use [`Catch`](https://github.com/philsquared/Catch) as unit-test framework

- Source files for each question in project should strtucured like:

    ```
    $id. $question_title
    ├──  solution.hpp    # implement the solution
    └──  TEST.cpp        # UNIT Testcases
    ```

    - You can generate this structure in `src` directory through command

        ```bash
        ./run.py gen "1. Two Sum"
        ```

- Now. Write Your Code !

    :thumbsup: which may looks like,
    ```c++
    /** 1. Two Sum/solution.hpp **/
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
    ```
    ```c++
    /** 1. Two Sum/TEST.cpp **/
    #include "../../framework/header.hpp"
    #include "../../framework/common.hpp"
    #include "solution.hpp"


    TEST_CASE( "TC for Two Sum", "[array]" ) {
        Solution s;

        vector<int> v = {1, 3, 4, 5, 6, 7, 2};
        REQUIRE( s.twoSum(v, 11) == vector<int>({2, 4}) );
    }

    ```

- Test it with one-line !

    ```bash
    ./run.py test 1

    ================================================   
      All tests passed (1 assertions in 1 test case)  
    ```

## Get the framework

Checkout the branch [framework](https://github.com/ovsoil/leetcode/tree/framework)  :facepunch:


## TODOS

- Auto get description of Problems from the leetcode web
- Sumit to leetcode web and get Run Time
