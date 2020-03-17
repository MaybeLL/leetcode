#include "iostream"
#include "dp/198.cpp"
#include <map>

using namespace std;

int main() {
    Solution_198 solution;
    vector<int> prices = {2, 7, 6, 3, 1};
    int res = solution.rob(prices);
    cout << res << endl;

    return 0;

}
