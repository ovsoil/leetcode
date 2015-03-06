/*
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        int index = 0;
        for(int i = index + 1; i < n; ++i){
            if(A[i] != A[index])
                A[++index] = A[i];
        }
        return index+1;
    }
};

int main()
{
    int A[10] = {1,1,1,3,3,3,3,6,10,10};
    Solution s;
    int n = s.removeDuplicates(A, 10);
    for(int i = 0; i < n; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
