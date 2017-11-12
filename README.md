# My leetcode practice with a unit test framework

 *Write leetcode code with C++11 and test them easily with full unit test features!*
 Use [`Catch2`](https://github.com/catchorg/Catch2) as unit-test framework

## Usage

- For each leetcode problem, generate source files at the `src` directory through command `./run.py gen "$id. $probem_title"`

    ```bash
    # ./run.py gen "$id. $probem_title"
    ./run.py gen "1. Two Sum"
    ```
    The generated files strtucured like:
    ```
    $id. $problem_title
    ├──  solution.hpp    # implement the solution
    └──  TEST.cpp        # UNIT Testcases
    ```

- Now. Write Your Code for test and solution!

    ```cpp
    /** 1. Two Sum/TEST.cpp **/
    #include "../../framework/header.hpp"
    #include "../../framework/common.hpp"
    #include "solution.hpp"

    TEST_CASE( "TC for Two Sum", "[leetcode]" ) {
        Solution s;

        vector<int> v = {1, 3, 4, 5, 6, 7, 2};
        REQUIRE( s.twoSum(v, 11) == vector<int>({2, 4}) );
    }

    ```

    ```cpp
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

- Test it with one-line !

    ```bash
    ./run.py test 1

    ================================================   
      All tests passed (1 assertions in 1 test case)  
    ```

## Get the framework

Checkout the branch [framework](https://github.com/ovsoil/leetcode/tree/framework):


## TODOS

- More programing language support (python, c, java)
- Auto get description of Problems from the leetcode web
- Sumit to leetcode web and get Run Time
