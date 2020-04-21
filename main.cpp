#include <iostream>
#include  <string>
#include <stack>
#include <vector>
#include "Divide-and-conquer/215.cpp"

using namespace std;



int main() {
    Solution s;
    vector<int> v = {1,18,3,2,5};
    int ans = s.findKthLargest(v,4);
    cout<<ans;
    return 0;
}
