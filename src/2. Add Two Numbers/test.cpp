#include <iostream>
#include <vector>
using namespace std;


int main(){
    int tmp = ({1,2} == vector<int>({1,2})? 1: 0); 
    cout << tmp << endl;
    return 0;
}
