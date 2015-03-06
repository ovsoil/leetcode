/*
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeElement(vector<int> &num, int value){
        auto end = num.end();

        for (auto i = num.begin(); i != end; ++i) {
            if(*i == value){
                while(*prev(end) == value)
                    --end;
                int tmp = *i;
                *i = *prev(end);
                *prev(end) = tmp;
                --end;
            }
        }
        return end - num.begin();
    }

    int removeElement2(vector<int> &num, int value){
        int index = 0;
        for (int i = 0; i < num.size(); ++i) {
            if(num[i] != value)
                num[index++] = num[i];
        }
        return index;
    }

    int removeElement3(vector<int> &num, int value){
        return distance(num.begin(), remove(num.begin(), num.end(), value));
    }
};


int main(int argc, const char *argv[])
{
    Solution s;

    vector<int> num = {
        2, 4, 5, 2, 6, 7, 9, 9, 2
    };
    int value = 2;

    cout << s.removeElement3(num, value) << endl;
    //cout << s.removeElement2(num, value) << endl;
    return 0;
}
