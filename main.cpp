#include "iostream"
#include "dp/53.cpp"
using namespace std;

int main()
{

    vector<int>a={-2};
    Solution_53 solution;

    int res = solution.maxSubArray(a);
    cout<<res<<endl;

    return 0;

}
