/*
 * 二分查找
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int search(int A[], int n, int target){
        int begin = 0, end = n;
        while(begin != end){
            const int mid = (begin + end)/2;
            if(target == A[mid])
                return mid;
            else if(target < A[mid])
                end = mid;
            else
                begin = mid + 1;
        }
        return -1;
    }

    int search2(int A[], int n, int target){
        int begin = 0, end = n;
        while(begin != end){
            const int mid = (begin + end)/2;
            if(target == A[mid])
                return mid;
            if(A[begin] <= A[mid]){
                if(A[begin] <= target && target < A[mid])
                    end = mid;
                else
                    begin = mid + 1;
            }
            else{
                if(A[mid] < target && target <= A[end - 1])
                    begin = mid + 1;
                else
                    end = mid;
            }
        }
        return -1;
    }


    int search3(int A[], int n, int target)
    {
        int begin = 0, end = n;
        while(begin != end){
            const int mid = (begin + end)/2;
            if(target == A[mid])
                return mid;
            if(A[begin] < A[mid]){
                if(A[begin] <= target && target < A[mid])
                    end = mid;
                else
                    begin = mid + 1;
            }else if (A[mid] < A[end]){
                if(A[mid] < target && target <= A[end - 1])
                    begin = mid + 1;
                else
                    end = mid;
            }else
                ++begin;
        }
        return -1;
    }
};



int main()
{
    int a[10] = {0, 3, 5 , 6, 8, 10, 23, 24, 26, 36};
    int b[10] = {23, 24, 26, 36, 0, 3, 5 , 6, 8, 10};
    int c[10] = {6, 24, 26, 26, 0, 0, 5 , 6, 6, 6};
    Solution s;

    cout << s.search(a, 10, 4) << endl;
    cout << s.search(a, 10, 26) << endl;
    cout << s.search(a, 10, 0) << endl;
    cout << s.search(a, 10, 36) << endl;

    cout << s.search2(b, 10, 4) << endl;
    cout << s.search2(b, 10, 26) << endl;
    cout << s.search2(b, 10, 0) << endl;
    cout << s.search2(b, 10, 36) << endl;

    cout << s.search3(c, 10, 4) << endl;
    cout << s.search3(c, 10, 26) << endl;
    cout << s.search3(c, 10, 0) << endl;
    cout << s.search3(c, 10, 6) << endl;

    return 0;
}
