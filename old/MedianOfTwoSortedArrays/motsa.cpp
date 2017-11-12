#include <iostream>
using namespace std;


class Solution{
public:
    int medianOfTwoSortedArrays(int A[], int m, int B[], int n){
        int *C = new int[m + n];
        mergeTwoSortedArrays(A, m, B, n, C);
        for (int i = 0; i < m+n; i++) {
            cout << C[i] << " ";
        }
        cout << endl;
        delete[] C;
    }

    void mergeTwoSortedArrays(int A[], int m, int B[], int n, int *C){
        int index = 0;
        int i, j;
        for (i = 0, j = 0; i < m && j < n; ) {
            if(A[i] <= B[j])
                C[index++] = A[i++];        
            else
                C[index++] = B[j++];
        }
        if(i == m)
            while(j < n)
                C[index++] = B[j++];
        else
            while(i < m)
                C[index++] = A[i++];
    }
};


int main()
{
    int a[10] = {1,2,4,5,6,7,9,10,22,30};
    int b[5] = {
        4, 5, 6, 7, 8
    };

    Solution s;
    s.medianOfTwoSortedArrays(a, 10, b, 5);
    return 0;
}
