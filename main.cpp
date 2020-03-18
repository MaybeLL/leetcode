#include <iostream>
#include "dp/anmoshi.cpp"
#include  <string>
#include <vector>

using namespace std;

int main() {
    vector<int> cost={2,7,9,3,1};
    Solution solution;
    int res = solution.massage(cost);
    cout<<res<<endl;
    return 0;

}
