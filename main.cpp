#include <iostream>
#include "dp/300.cpp"
#include  <string>
#include <vector>

using namespace std;

int main() {
    Solution solution;
//    s = "leetcode", wordDict = ["leet", "code"]
//    "bb"
//    ["a","b","bbb","bbbb"]
//    string s = "bb";
    vector<int> test={10,9,2,5,3,7,101,18,19};
    int res =solution.lengthOfLIS(test);
    cout<<res<<endl;
    return 0;



}
