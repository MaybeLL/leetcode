#include <iostream>
#include  <string>
#include <stack>
#include <vector>
#include "Tree/middle/129.cpp"

using namespace std;



int main() {
    Solution s;

    vector<int> v = {1,2,3,4,5};
    vector<int> v2;
    v2 = assign(v.begin(),v.begin()+v.size());
    for(auto x:v2){
        cout<<x<<",";
    }
    return 0;
}
